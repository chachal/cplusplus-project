#include "physics.hpp"
#include <SFML/Graphics.hpp>

class Box{
  public:		
    sf::Texture birdTexture;		
    sf::RectangleShape bird;
    void init();
    void updatepos(sf::Vector2f pos);

};

class Bird{
  public:		
    sf::Texture birdTexture;		
    sf::CircleShape bird;
    void init();
    void updatepos(sf::Vector2f pos);
};

class Pig{
  public:		
    sf::Texture birdTexture;		
    sf::CircleShape bird;
    void init();
    void updatepos(sf::Vector2f pos);
};
