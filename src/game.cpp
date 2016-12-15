#include "game.hpp"

using namespace std;

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

void game(sf::Sprite* background, sf::RenderWindow* win)
{
  string levelnmb = "1";
  const float SCALE = 30.f;
  cout<<"STARTING"<<endl;
  

  sf::Sprite slingshot;
  sf::Texture slingshottex;
  slingshottex.loadFromFile("Sprites/slingshot.png");
  slingshot.setTexture(slingshottex);
  slingshot.setPosition(155, 340);
  
  b2Vec2 gravity(0.0f, 9.8f);
  b2World world(gravity);
  b2BodyDef groundBodyDef;
  groundBodyDef.position.Set(0.0f, 16.6f);
  b2Body* groundBody = world.CreateBody(&groundBodyDef);
  b2PolygonShape groundBox;
  groundBox.SetAsBox(50.0f, 1.0f);
  groundBody->CreateFixture(&groundBox, 0.0f);
  float32 timeStep = 1.f/6000.f;
  int32 velocityIterations = 8;	
  int32 positionIterations = 3;
  
  std::vector<std::pair<RectBody, Bird> > blocks;
  std::vector<std::pair<CircleBody, Bird2> > birds2;
  std::vector<std::pair<CircleBody, Pig> > pigs;
  
  Worldbuilder(levelnmb, &world, &blocks, &pigs, &birds2);
  for (auto jt = blocks.begin(); jt != blocks.end(); jt++) {
    jt->second.init();
  }
  for (auto kt = birds2.begin(); kt != birds2.end(); kt++) {
    kt->second.init();
  }
  for (auto kt = pigs.begin(); kt != pigs.end(); kt++) {
    kt->second.init();
  }


  bool canlaunch = false;
  sf::Vector2i mousepos;
  sf::Vector2i startpos(190, 370);
  sf::Vector2i impact;

  bool physics = false;
  bool pressed = false;
  bool onair = false;
  
  size_t len = blocks.size();
  sf::Clock kello2;

  while (win->isOpen()) {
    win->clear();
    win->draw(*background);
    win->draw(slingshot);
    size_t len = blocks.size();
    float d = kello2.restart().asSeconds();

    for (int i = 0; i < len; i++){
      b2Vec2 pos = blocks[i].first.getposition();
      sf::Vector2f position = sf::Vector2f(pos.x*SCALE,pos.y*SCALE);
      blocks[i].second.updatepos(position);
      float rotation = blocks[i].first.body->GetAngle();
      blocks[i].second.bird.setRotation(rotation*180/3.14f);
      win->draw(blocks[i].second.bird);
    }
    len = pigs.size();
    for (int i = 0; i < len; i++){
      b2Vec2 pos = pigs[i].first.getposition();
      sf::Vector2f position = sf::Vector2f(pos.x*SCALE,pos.y*SCALE);
      pigs[i].second.updatepos(position);
      float rotation = pigs[i].first.body->GetAngle();
      pigs[i].second.bird.setRotation(rotation*180/3.14f);
      win->draw(pigs[i].second.bird);
    }
    len = birds2.size();
    for (int i = 0; i < len; i++){
      sf::Vector2f position;
      if(physics){
        b2Vec2 pos = birds2[i].first.getposition();
        position = sf::Vector2f(pos.x*SCALE, pos.y*SCALE);
        float rotation = birds2[i].first.body->GetAngle();
        birds2[i].second.bird.setRotation(rotation*180/3.14f);
      } else if (pressed){
        checkimpact(&impact);
        sf::Vector2i pos(startpos.x - impact.x, startpos.y - impact.y);
        position = sf::Vector2f(pos.x, pos.y);
      } else{
        position = sf::Vector2f(startpos.x, startpos.y);
      }
      birds2[i].second.updatepos(position);
      win->draw(birds2[i].second.bird);
    }
    
    mousepos = sf::Mouse::getPosition(*win);
    impact = startpos - mousepos;
    
    
    if (canlaunch){
      checkimpact(&impact);
      physics = true;
      birds2.back().first.body->ApplyLinearImpulse(b2Vec2(impact.x/1.2f ,impact.y/1.2f), birds2.back().first.body->GetWorldCenter(), true);
      canlaunch = false;
    }
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
          if(impact.x < 50 && impact.x > -50 && impact.y < 50 && impact.y > -50){
            pressed = true;
          break;
          }
        case sf::Event::MouseButtonReleased:
          if(pressed){
            canlaunch = true;
            pressed = false;
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



