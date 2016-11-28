#include "physics.hpp"
#include <iostream>
#include <time.h>
#include <SFML/System.hpp>

int main() {
  RigidbodySquare rect;
  rect.init(5,4,3,2);
  sf::Clock kello;

  while (1) {
    int delta = kello.getElapsedTime().asMilliseconds();
    if (delta > 1000/60) {
      kello.restart();
      rect.gravity();
      std::cout << rect.posy << std::endl;
    }
  }
}
