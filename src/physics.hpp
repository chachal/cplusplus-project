#include <SFML/System.hpp>

class RigidbodySquare{
  sf::Vector2f size, pos;
  public:
    void init(sf::Vector2f s, sf::Vector2f p);
    void gravity();
    sf::Vector2f getcoords();
};

class RigidbodyCircle{
  public:
    float radius, posx, posy;
  void init(float r, float x, float y);
};
