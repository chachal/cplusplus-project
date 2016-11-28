#include "physics.hpp"
#include <utility>

void RigidbodySquare::init(float h, float w, float x, float y){
  height = h;
  width = w;
  posx = x;
  posy = y;
}

void RigidbodyCircle::init(float r, float x, float y){
  radius = r;
  posx = x;
  posy = y;
}

void RigidbodySquare::gravity(){
  posy = posy - 1;
}
