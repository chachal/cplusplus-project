#include "physics.hpp"
#include <SFML/Graphics.hpp>

class Bird{
		sf::RectangleShape bird;
		sf::Texture birdTexture;
		RigidbodySquare rdbd;
	public:
		void init(sf::Vector2f size, sf::Vector2f position);
		void updatepos();
};
