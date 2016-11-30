#include "Physics.h"
#include "Animation.h"
#include <SFML/Graphics.hpp>

class Bird {
	RigidbodySquare rdbd;
public:
	Animation animation;
	sf::Texture birdTexture;
	sf::RectangleShape bird;
	void init(sf::Vector2f size, sf::Vector2f position);
	void updatepos();
	void updateanim(float delta);
};
