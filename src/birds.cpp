#include <iostream>
#include "birds.hpp"

void Bird::init(float type){
  bird.setFillColor(sf::Color::Alpha);
  bird.setPosition(sf::Vector2f(0,0));
}

void Bird::updatepos(sf::Vector2f pos){
  bird.setPosition(pos);
}

void Red::updateanim(float delta){
  anim.Update(delta, 0);
  bird.setTextureRect(anim.uvRect);	
}

void Red::init(){
  bird.setTexture(&birdTexture);
  anim.init(&birdTexture, sf::Vector2u(10, 1), 0.1f);
  birdTexture.loadFromFile("Sprites/red.png");
  bird.setOrigin(33.f, 28.f);
  bird.setSize(size);
}
