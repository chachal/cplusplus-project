#include <utility>
#include <iostream>
#include "graphics.hpp"



void RectBody::init(b2World world){
  bodyDef.type = b2_dynamicBody;
  bodyDef.position.Set(0.0f, 4.0f);
  bodyDef.position.Set(0.0f, 4.0f);
  b2Body* body = world.CreateBody(&bodyDef);

  b2PolygonShape dynamicBox;
  dynamicBox.SetAsBox(1.0f, 1.0f);

  b2FixtureDef fixtureDef;
  fixtureDef.shape = &dynamicBox;
  fixtureDef.density = 1.0f;
  fixtureDef.friction = 0.3f;

  body->CreateFixture(&fixtureDef);

}

b2Vec2 RectBody::getposition(){
  b2Vec2 position = body->GetPosition();
  return position;
}




