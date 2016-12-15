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
  
  
  createSquares(&birds, &world, b2Vec2(20.0f, 0.f));
  createCircles(&birds2, &world, b2Vec2(20.4f, -1.f));
  size_t len = birds.size();
  sf::Clock kello2;

  while (win.isOpen()) {
    

    win.clear();
    win.draw(background);
    size_t len = birds.size();
    float d = kello2.restart().asSeconds();

    for (int i = 0; i < len; i++){
      b2Vec2 pos = birds[i].first.getposition();
      float x = pos.x*SCALE;
      float y = pos.y*SCALE;
      sf::Vector2f position = sf::Vector2f(x,y);
      birds[i].second.updatepos(position);
      birds[i].second.bird.setRotation(birds2[i].first.body->GetAngle());

      win.draw(birds[i].second.bird);
    }
    len = birds2.size();
    for (int i = 0; i < len; i++){
      b2Vec2 pos = birds2[i].first.getposition();
      float x = pos.x*SCALE;
      float y = pos.y*SCALE;
      sf::Vector2f position = sf::Vector2f(x,y);
      birds2[i].second.updatepos(position);
      birds2[i].second.bird.setRotation(birds2[i].first.body->GetAngle());

      win.draw(birds2[i].second.bird);
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
      }
    }
    world.Step(timeStep, velocityIterations, positionIterations);
    win.display();
  }
}
