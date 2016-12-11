#include <iostream>
#include "StateMachine.hpp"
#include "GStateMachine.hpp"
#include <SFML/Window.hpp>
#include "graphics.hpp"
#include <list>

using namespace std;

static void event_loop()
{
    int mode = 0;
    //mode 1 == pelissä, tähän voi lisäillä modeja menuun mitä haluaa
    //mainin piirto
    //keylistenerit / mouse listener millä vaihdetaan tota modea sfml avulla että pääsee peliin
    // jos modeja tulee enemmän niin vaihtaa ton if silmukan switchiksi, jne.
    if (mode != 0){


    }


}

void createObjects(std::vector<std::pair<RectBody, Bird> >* birds, b2World* world)
{
  Bird b;
  b.init(sf::Vector2f(63.0f, 65.0f), sf::Vector2f(50.0f, 50.0f));
  RectBody a;
  a.init(world);
  birds->push_back(std::make_pair(a,b));
}

int main()
{
  cout<<"STARTING"<<endl;
  sf::RenderWindow win(sf::VideoMode(960, 540), "Angry Birds");

  b2Vec2 gravity(0.0f, -10.0f);
  b2World world(gravity);
  b2BodyDef groundBodyDef;
  groundBodyDef.position.Set(0.0f, -1.0f);
  b2Body* groundBody = world.CreateBody(&groundBodyDef);
  b2PolygonShape groundBox;
  groundBox.SetAsBox(50.0f, 10.0f);
  groundBody->CreateFixture(&groundBox, 0.0f);
  float32 timeStep = 1.0f/1.0f;
  int32 velocityIterations = 8;	
  int32 positionIterations = 3;
  
  std::vector<std::pair<RectBody, Bird> > birds;
  
  createObjects(&birds, &world);
  size_t len = birds.size();
  sf::Clock kello2;

  while (win.isOpen()) {
    
    world.Step(timeStep, velocityIterations, positionIterations);
    win.clear();
    size_t len = birds.size();
    float d = kello2.restart().asSeconds();

    //cout << len << endl;
    for (int i = 0; i < len; i++){
      b2Vec2 pos = birds[i].first.getposition();
      float x = pos.x;
      float y = pos.y;
      sf::Vector2f position = sf::Vector2f(x,y);
      birds[i].second.updatepos(position);
      birds[i].second.updateanim(d);
      win.draw(birds[i].second.bird);
      cout << y << endl;
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
    win.display();
  }
  event_loop();
  return 0;
}


