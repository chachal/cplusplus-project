#include <SFML/System.hpp>

class RigidbodySquare{
  sf::Vector2f size, pos, vel;
  
  public:
    void init(sf::Vector2f s, sf::Vector2f p);
    sf::Vector2f updateposition();
};

class RigidbodyCircle{
  public:
    float radius, posx, posy;
    void init(float r, float x, float y);
};
