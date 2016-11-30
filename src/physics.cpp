#include <utility>
#include <iostream>
#include "graphics.hpp"

void RigidbodySquare::init(sf::Vector2f s, sf::Vector2f p){
  size = s;
  pos = p;
  vel.x = 5;
  vel.y = 10;
}

void RigidbodyCircle::init(float r, float x, float y){
  radius = r;
  posx = x;
  posy = y;
}

sf::Vector2f RigidbodySquare::updateposition(){
  if(pos.y > 550){
	vel.y = -10;
  }
  if(pos.x > 750){
	vel.x = -5;
  }
  if(pos.x < 50){
	vel.x = 5;
  }
  vel.y = vel.y + 0.1;		//gravity
  pos = pos + vel;
  return pos;
}

sf::Vector2f RigidbodySquare::getcoords(){
  return pos;
}

