#include "physics.hpp"
#include <utility>
#include <iostream>

void RigidbodySquare::init(sf::Vector2f s, sf::Vector2f p){
  size = s;
  pos = p;
}

void RigidbodyCircle::init(float r, float x, float y){
  radius = r;
  posx = x;
  posy = y;
}

void RigidbodySquare::gravity(){
  pos.y = pos.y - 1;
}

sf::Vector2f RigidbodySquare::getcoords(){
  return pos;
}
