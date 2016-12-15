#include "physics.hpp"
#include "Animation.hpp"
#include <SFML/Graphics.hpp>

class Bird{
	public:		
		sf::Texture birdTexture;		
		sf::RectangleShape bird;
		void init();
		void updatepos(sf::Vector2f pos);
		void updateanim(float delta);
		Animation anim;
};

class Bird2{
	public:		
		sf::Texture birdTexture;		
		sf::CircleShape bird;
		void init();
		void updatepos(sf::Vector2f pos);
		void updateanim(float delta);
		Animation anim;
};

class Pig{
  public:		
    sf::Texture birdTexture;		
    sf::CircleShape bird;
    void init();
    void updatepos(sf::Vector2f pos);
    void updateanim(float delta);
    Animation anim;
};
