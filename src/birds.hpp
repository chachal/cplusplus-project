#include "physics.hpp"
#include "Animation.hpp"
#include <SFML/Graphics.hpp>

class Bird{
  public:		    
    void init(float type);
    void updatepos(sf::Vector2f pos);
    sf::Shape bird;
};

class Red: public Bird{
  public:
    sf::Texture birdTexture;			
    void init();
    void updateanim(float delta);
    Animation anim;
    float mass;
    sf::Vector2f size;
};
