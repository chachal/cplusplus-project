#include "game.hpp"
#include <chrono>
#include <thread>
#include <vector>

using namespace std;

//Limit the about be launch bird near the launch pad
void checkimpact(sf::Vector2i* impact){
  if(impact->x > 50){
    impact->x = 50;
  }
  if(impact->y > 50){
    impact->y = 50;
  }
  if(impact->x < -50){
    impact->x = -50;
  }
  if(impact->y < -50){
    impact->y = -50;
  }
}


//The main game loop
void game(sf::Sprite* background, sf::RenderWindow* win, std::string level)
{
  string levelnmb = level;
  const float SCALE = 30.f;
  cout<<"STARTING"<<endl;
  
  //Set up camera, static objects
  sf::View view(sf::FloatRect(0,0,960,540));

  sf::Sprite slingshot;
  sf::Texture slingshottex;
  slingshottex.loadFromFile("Sprites/slingshot.png");
  slingshot.setTexture(slingshottex);
  slingshot.setPosition(155, 340);

  sf::Font font;
  font.loadFromFile("Fonts/font.ttf");
  sf::Text text;
  text.setCharacterSize(30);
  text.setStyle(sf::Text::Bold);
  text.setColor(sf::Color::Black);
  text.setFont(font);

  sf::SoundBuffer buffer;
  buffer.loadFromFile("Audio/sound.wav");
  sf::Sound launch;
  sf::Sound sound;
  sound.setBuffer(buffer);

  //Set up physics simulation with Box2D
  b2Vec2 gravity(0.0f, 9.8f);
  b2World world(gravity);
  b2BodyDef groundBodyDef;
  groundBodyDef.position.Set(0.0f, 16.6f);
  b2Body* groundBody = world.CreateBody(&groundBodyDef);
  b2PolygonShape groundBox;
  groundBox.SetAsBox(100.0f, 1.0f);
  groundBody->CreateFixture(&groundBox, 0.0f);
  float32 timeStep = 1.f/6000.f;
  int32 velocityIterations = 8;	
  int32 positionIterations = 3;


  //Vectors to store gameobjects and their physics references  
  std::vector<std::pair<RectBody, Box> > blocks;
  std::vector<std::pair<CircleBody, Bird> > birds;
  std::vector<std::pair<CircleBody, Pig> > pigs;
  
  //Call worldbuilder to generate level based on csv files
  Worldbuilder(levelnmb, &world, &blocks, &pigs, &birds);
  for (auto jt = blocks.begin(); jt != blocks.end(); jt++) {
    jt->second.init();
  }
  for (auto kt = birds.begin(); kt != birds.end(); kt++) {
    kt->second.init();
  }
  for (auto kt = pigs.begin(); kt != pigs.end(); kt++) {
    kt->second.init();
  }

  //Setting up booleans to track different states of game
  bool canlaunch = false;
  bool physics = false;
  bool pressed = false;
  bool onair = false;
  bool special = false;
  
  //PLACEHOLDER for point count
  int points = 0;  

  //Mousetracking for launch
  sf::Vector2i mousepos;
  sf::Vector2i startpos(190, 370);
  sf::Vector2i impact;


  while (win->isOpen()) {
    win->clear();
    win->draw(*background);
    win->draw(slingshot);
    win->draw(text);
    text.setString("Points: " + std::to_string(points));
    text.setPosition(win->mapPixelToCoords(sf::Vector2i(0,0)));

    //Game ends when player is out of birds (should add pigs as well)
    if(birds.empty()){
      text.setString("Points: " + std::to_string(points) + " Game Over");
      text.setPosition(win->mapPixelToCoords(sf::Vector2i(350,270)));
      return;
    } 

    //Update and draw all objects based on their physics simulations
    //Blocks
    size_t len = blocks.size();
    for (unsigned int i = 0; i < len; i++){
      b2Vec2 pos = blocks[i].first.getposition();
      sf::Vector2f position = sf::Vector2f(pos.x*SCALE,pos.y*SCALE);
      blocks[i].second.updatepos(position);
      float rotation = blocks[i].first.body->GetAngle();
      blocks[i].second.bird.setRotation(rotation*180/3.14f);
      win->draw(blocks[i].second.bird);
    }
    //Pigs
    len = pigs.size();
    for (unsigned int i = 0; i < len; i++){
      b2Vec2 pos = pigs[i].first.getposition();
      sf::Vector2f position = sf::Vector2f(pos.x*SCALE,pos.y*SCALE);
      pigs[i].second.updatepos(position);
      float rotation = pigs[i].first.body->GetAngle();
      pigs[i].second.bird.setRotation(rotation*180/3.14f);
      win->draw(pigs[i].second.bird);

      //If a bird collides with a pig:
      for(b2ContactEdge* edge = pigs[i].first.body->GetContactList(); edge; edge = edge->next){
        b2Body* a = edge->other;
        if (a->IsBullet()){
          pigs[i].second.hp--;
        }
      }
      if (pigs[i].second.hp <= 0){
        auto it = pigs.begin() + int(i);
        pigs.erase(it);
        points = points + 500;
      }
    }
    //Birds
    len = birds.size();
    for (unsigned int i = 0; i < len; i++){
      sf::Vector2f position;
      if(physics){
        b2Vec2 pos = birds[i].first.getposition();
        position = sf::Vector2f(pos.x*SCALE, pos.y*SCALE);
        float rotation = birds[i].first.body->GetAngle();
        birds[i].second.bird.setRotation(rotation*180/3.14f);
      } else if (pressed){
        checkimpact(&impact);
        sf::Vector2i pos(startpos.x - impact.x, startpos.y - impact.y);
        position = sf::Vector2f(pos.x, pos.y);
      } else{
        position = sf::Vector2f(startpos.x, startpos.y);
      }
      birds[i].second.updatepos(position);
      
      //Camera tracks currently selected bird with set boundaries
      if(birds[i].first.getposition().x*SCALE <= 480){
        view.setCenter(480,270);
      }else{
        view.setCenter(birds[i].first.getposition().x*SCALE,270);
      }
      win->draw(birds[i].second.bird);
      
      //Destroy active bird if it goes out of game area and reset game state booleans
      if (birds[i].first.getposition().x*SCALE >= 1300 || birds[i].first.getposition().x*SCALE < 100){
        birds.pop_back();
        physics = false;
        pressed = false;
        onair = false;
        special = false;
      }
    }
    
    win->setView(view);
    
    mousepos = sf::Mouse::getPosition(*win);
    impact = startpos - mousepos;
    
    //Apply force to bird
    if (canlaunch){
      checkimpact(&impact);
      physics = true;
      birds.back().first.body->ApplyLinearImpulse(b2Vec2(impact.x/1.2f ,impact.y/1.2f), birds.back().first.body->GetWorldCenter(), true);
      canlaunch = false;
      sound.play();
    }

    //SFML event listener
    sf::Event evnt;
    while (win->pollEvent(evnt)) {
      switch (evnt.type) {
        case sf::Event::Closed:
          win->close();
          break;
        case sf::Event::Resized:
          printf("Uusi leveys: %i Uusi korkeus: %i\n", evnt.size.width, evnt.size.height); 
          break;
        case sf::Event::MouseButtonPressed:
          if(impact.x < 50 && impact.x > -50 && impact.y < 50 && impact.y > -50 && onair == false){
            pressed = true;
          }
          //Special ability for bird
          if(onair == true && special == true){
            birds.back().first.body->ApplyLinearImpulse(b2Vec2 (100 ,100), birds.back().first.body->GetWorldCenter(), true);
            special = false;
          }
          break;
        case sf::Event::MouseButtonReleased:
          if(pressed){
            canlaunch = true;
            pressed = false;
            special = true;
            onair = true;
          break;  
        }
      }
    }
    if(physics){
      world.Step(timeStep, velocityIterations, positionIterations);
    }
    win->display();
  }
}



