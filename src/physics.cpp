#include <utility>
#include <iostream>
#include "birds.hpp"

void RectBody::init(b2World* world, b2Vec2 pos){
  b2BodyDef bodyDef;
  bodyDef.type = b2_dynamicBody;
  bodyDef.position.Set(pos.x, pos.y);
  body = world->CreateBody(&bodyDef);

  b2PolygonShape dynamicBox;
  dynamicBox.SetAsBox(1.1f, 1.1f);

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

void CircleBody::init(b2World* world, b2Vec2 pos){
  b2BodyDef bodyDef;
  bodyDef.type = b2_dynamicBody;
  bodyDef.position.Set(pos.x, pos.y);
  body = world->CreateBody(&bodyDef);

  b2CircleShape circleShape;
  circleShape.m_p.Set(0.0f, 0.0f);
  circleShape.m_radius = 0.9f;
  
  b2FixtureDef fixtureDef;
  fixtureDef.shape = &circleShape;
  fixtureDef.density = 1.0f;
  fixtureDef.friction = 0.3f;

  body->CreateFixture(&fixtureDef);

}

b2Vec2 CircleBody::getposition(){
  b2Vec2 position = body->GetPosition();
  return position;
}



