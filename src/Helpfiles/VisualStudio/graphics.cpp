#include <iostream>
#include "graphics.h"

void Bird::init(sf::Vector2f size, sf::Vector2f position, int type) {
	bird.setSize(size);
	bird.setFillColor(sf::Color::White);
	bird.setOrigin((size.x/2), (size.y/2));
	bird.setPosition(position);
	birdTexture.loadFromFile("birds.png");
	bird.setTexture(&birdTexture);
	anim.init(&birdTexture, sf::Vector2u(10, 1), 0.1f);
}

void Bird::updatepos() {
	std::cout << "a" << std::endl;

}

void Bird::updateanim(float delta) {
	anim.Update(delta, 0);
	bird.setTextureRect(anim.uvRect);

}

void Block::init(sf::Vector2f position, int type, float angle) {
	block.setSize(sf::Vector2f(25.0f, 25.0f));
	block.setFillColor(sf::Color::Black);
	block.setPosition(position);
	blockTexture.loadFromFile("blocks.png");
	block.setTexture(&blockTexture);
}

void Pig::init(sf::Vector2f position, int type) {
	pig.setSize(sf::Vector2f(25.0f, 25.0f));
	pig.setFillColor(sf::Color::Red);
	pig.setPosition(position);
	pigTexture.loadFromFile("pigs.png");
	pig.setTexture(&pigTexture);
}

/*	Animation animation(&birdTexture, sf::Vector2u(10, 1), 0.1f);

float delta = 0.0f;
sf::Clock kello;

while (win.isOpen()) {
delta = kello.restart().asSeconds();

sf::Event evnt;
while (win.pollEvent(evnt)) {
switch (evnt.type) {
case sf::Event::Closed:
win.close();
break;
case sf::Event::Resized:
printf("Uusi leveys: %i Uusi korkeus: %i\n", evnt.size.width, evnt.size.height);
break;
}
}
if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
sf::Vector2i mousepos = sf::Mouse::getPosition(win);
bird.setPosition(static_cast<float>(mousepos.x), static_cast<float>(mousepos.y));
}

animation.Update(delta, 0);
bird.setTextureRect(animation.uvRect);
win.clear(sf::Color::White);
win.draw(bird);
win.display();
}
return 0;
}*/
