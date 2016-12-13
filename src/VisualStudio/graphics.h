#include "Physics.h"
#include "Animation.h"
#include <SFML/Graphics.hpp>

class Bird {
public:
	sf::Texture birdTexture;
	sf::RectangleShape bird;
	void init(sf::Vector2f size, sf::Vector2f position, int type);
	void updatepos();
	void updateanim(float delta);
	Animation anim;
};

class Block {
public:
	sf::Texture blockTexture;
	sf::RectangleShape block;
	void init(sf::Vector2f position, int type, float angle);
};

class Pig {
public:
	sf::Texture pigTexture;
	sf::RectangleShape pig;
	void init(sf::Vector2f position, int type);
};
