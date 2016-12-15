#include <iostream>
#include "birds.hpp"

void Bird::init(){
	bird.setOrigin(33.f, 28.f);
	bird.setPosition(0,0);
	birdTexture.loadFromFile("Sprites/red2.png");
	bird.setTexture(birdTexture);
}

void Bird::updatepos(sf::Vector2f pos){
        bird.setPosition(pos);
}


void Bird2::init(){
	bird.setRadius(28.0f);
        bird.setRotation(0.f);
	bird.setOrigin(28.f, 28.f);
	bird.setPosition(0,0);
	birdTexture.loadFromFile("Sprites/red.png");
	bird.setTexture(&birdTexture);
    
}

void Bird2::updatepos(sf::Vector2f pos){
        bird.setPosition(pos);
}

