#include <SFML/Graphics.hpp>
#include <iostream>
#include "graphics.h"

int main()
{
	sf::RenderWindow win(sf::VideoMode(1024, 1024), "Angry Birds", sf::Style::Default);
	
	Bird birdie;
	birdie.init(sf::Vector2f(63.0f, 65.0f), sf::Vector2f(50.0f, 50.0f));
	//sf::RectangleShape bird(sf::Vector2f(63.0f, 65.0f));
	//bird.setFillColor(sf::Color::White);
	//bird.setOrigin(31.5f, 32.5f);
	//bird.setPosition(50.0f, 50.0f);
	//sf::Texture birdTexture;
	//birdTexture.loadFromFile("birds.png");
	//bird.setTexture(&birdTexture);

	//Animation animation(&(birdie.birdTexture), sf::Vector2u(10, 1), 0.1f);

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
			(birdie.bird).setPosition(static_cast<float>(mousepos.x), static_cast<float>(mousepos.y));
		}
		birdie.updatepos();
		birdie.updateanim(delta);
		win.clear(sf::Color::White);
		win.draw(birdie.bird);
		win.display();
	}
	return 0;
}
