#include "game.hpp"

using namespace std;

void createSquares(std::vector<std::pair<RectBody, Bird> >* birds, b2World* world, b2Vec2 pos)
{
  RectBody a;
  Bird b;
  a.init(world, pos);    
  b.init();
  birds->push_back(std::make_pair(a,b));
}
void createCircles(std::vector<std::pair<CircleBody, Bird2> >* birds, b2World* world, b2Vec2 pos)
{
  CircleBody a;
  Bird2 b;
  a.init(world, pos);    
  b.init();
  birds->push_back(std::make_pair(a,b));
}

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

void game()
{

  const float SCALE = 30.f;
  cout<<"STARTING"<<endl;
  sf::RenderWindow win(sf::VideoMode(960, 540), "Angry Birds");
  sf::Sprite background;
  sf::Texture backgroundTex;
  backgroundTex.loadFromFile("Sprites/bg.png");
  background.setTexture(backgroundTex);
  background.setPosition(0,-205);

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
  
  std::vector<std::pair<RectBody, Bird> > birds;
  std::vector<std::pair<CircleBody, Bird2> > birds2;

  bool canlaunch = false;
  sf::Vector2i mousepos;
  sf::Vector2i startpos(190, 370);
  sf::Vector2i impact;

  bool physics = false;
  bool pressed = false;
  bool onair = false;
  
  //createSquares(&birds, &world, b2Vec2(20.0f, 0.f));
  createCircles(&birds2, &world, b2Vec2(startpos.x/SCALE, startpos.y/SCALE));
  size_t len = birds.size();
  sf::Clock kello2;

  while (win.isOpen()) {
    

    win.clear();
    win.draw(background);
    win.draw(slingshot);
    size_t len = birds.size();
    float d = kello2.restart().asSeconds();

    for (int i = 0; i < len; i++){
      b2Vec2 pos = birds[i].first.getposition();
      sf::Vector2f position = sf::Vector2f(pos.x*SCALE,pos.y*SCALE);
      birds[i].second.updatepos(position);
      birds[i].second.bird.setRotation(birds2[i].first.body->GetAngle());

      win.draw(birds[i].second.bird);
    }
    len = birds2.size();
    for (int i = 0; i < len; i++){
      sf::Vector2f position;
      if(physics){
        b2Vec2 pos = birds2[i].first.getposition();
        position = sf::Vector2f(pos.x*SCALE, pos.y*SCALE);
        birds2[i].second.bird.setRotation(birds2[i].first.body->GetAngle());
      } else if (pressed){
        checkimpact(&impact);
        sf::Vector2i pos(startpos.x - impact.x, startpos.y - impact.y);
        position = sf::Vector2f(pos.x, pos.y);
      } else{
        position = sf::Vector2f(startpos.x, startpos.y);
      }
      birds2[i].second.updatepos(position);
      win.draw(birds2[i].second.bird);
    }
    
    mousepos = sf::Mouse::getPosition(win);
    impact = startpos - mousepos;
    
    
    if (canlaunch){
      checkimpact(&impact);
      physics = true;
      birds2.back().first.body->ApplyLinearImpulse(b2Vec2(impact.x/1.2f ,impact.y/1.2f), birds2.back().first.body->GetWorldCenter(), true);
      canlaunch = false;
    }
    sf::Event evnt;
    while (win.pollEvent(evnt)) {
      switch (evnt.type) {
        case sf::Event::Closed:
          win.close();
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
    win.display();
  }
}



