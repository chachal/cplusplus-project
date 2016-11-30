#include "physics.hpp"
#include <SFML/Graphics.hpp>

class Bird{
		RigidbodySquare rdbd;
	public:		
		sf::Texture birdTexture;		
		sf::RectangleShape bird;
		void init(sf::Vector2f size, sf::Vector2f position);
		void updatepos();
};
