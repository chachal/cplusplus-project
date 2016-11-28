#include "physics.hpp"
#include <iostream>
#include <time.h>
#include <SFML/System.hpp>
#include <vector>

int main() {
  std::vector<RigidbodySquare> squares;
  RigidbodySquare rect;
  sf::Vector2f v1(5,5);
  sf::Vector2f v2(0,1000);
  rect.init(v1, v2);  
  squares.push_back(rect);
  sf::Clock kello;

  while (1) {
    int delta = kello.getElapsedTime().asMilliseconds();
    if (delta > 1000/60) {
      kello.restart();
      for(int i = 0; i < squares.size(); i++)
      { 
        RigidbodySquare& r = squares[i];
        r.gravity();      
        std::cout << r.getcoords().y << std::endl;
      }
    }
  }
}
