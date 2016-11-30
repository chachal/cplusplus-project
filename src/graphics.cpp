#include <iostream>
#include "graphics.hpp"

void Bird::init(sf::Vector2f size, sf::Vector2f position){
	bird.setSize(size);
	bird.setFillColor(sf::Color::White);
	bird.setOrigin(31.5f, 32.5f);
	bird.setPosition(position);
	birdTexture.loadFromFile("birds.png");
	bird.setTexture(&birdTexture);
	rdbd.init(size, position);
	anim.init(&birdTexture, sf::Vector2u(10, 1), 0.1f);  
}

void Bird::updatepos(){ 
	bird.setPosition(rdbd.updateposition());
        std::cout << rdbd.getcoords().y << std::endl;
	
}

void Bird::updateanim(float delta){
	anim.Update(delta, 0);
	bird.setTextureRect(anim.uvRect);
	
}
