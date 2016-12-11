#include "physics.hpp"
#include "Animation.hpp"
#include <SFML/Graphics.hpp>

class Bird{
	public:		
		sf::Texture birdTexture;		
		sf::RectangleShape bird;
		void init(sf::Vector2f size, sf::Vector2f position);
		void updatepos(sf::Vector2f pos);
		void updateanim(float delta);
		Animation anim;
};
