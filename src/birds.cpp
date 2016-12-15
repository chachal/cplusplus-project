#include <iostream>
#include "birds.hpp"

void Bird::init(){
	bird.setSize(sf::Vector2f(66.0f, 56.0f));
	bird.setFillColor(sf::Color::White);
	bird.setOrigin(33.f, 28.f);
	bird.setPosition(0,0);
	birdTexture.loadFromFile("Sprites/red.png");
	bird.setTexture(&birdTexture);
	anim.init(&birdTexture, sf::Vector2u(5, 1), 0.1f);      
}

void Bird::updatepos(sf::Vector2f pos){
        bird.setPosition(pos);
}

void Bird::updateanim(float delta){
	anim.Update(delta, 0);
	bird.setTextureRect(anim.uvRect);
}

void Bird2::init(){
	bird.setRadius(28.0f);
        bird.setRotation(0.f);
	bird.setFillColor(sf::Color::White);
	bird.setOrigin(28.f, 28.f);
	bird.setPosition(0,0);
	birdTexture.loadFromFile("Sprites/red.png");
	bird.setTexture(&birdTexture);
	anim.init(&birdTexture, sf::Vector2u(5, 1), 0.1f);      
}

void Bird2::updatepos(sf::Vector2f pos){
        bird.setPosition(pos);
}

void Bird2::updateanim(float delta){
	anim.Update(delta, 0);
	bird.setTextureRect(anim.uvRect);
}
