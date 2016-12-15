#include <iostream>
#include "birds.hpp"

void Bird::init(){
  bird.setSize(sf::Vector2f(66.0f, 56.0f));
  bird.setOrigin(33.f, 28.f);
  bird.setPosition(0,0);
  birdTexture.loadFromFile("Sprites/box.png");
  bird.setTexture(&birdTexture);
    
}

void Bird::updatepos(sf::Vector2f pos){
  bird.setPosition(pos);
}


void Bird2::init(){
  bird.setRadius(25.0f);
  bird.setRotation(0.f);
  bird.setOrigin(25.f, 25.f);
  bird.setPosition(0,0);
  birdTexture.loadFromFile("Sprites/red.png");
  bird.setTexture(&birdTexture);

}

void Bird2::updatepos(sf::Vector2f pos){
  bird.setPosition(pos);
}


void Pig::init(){
  bird.setRadius(28.0f);
  bird.setRotation(0.f);
  bird.setOrigin(28.f, 28.f);
  bird.setPosition(0,0);
  birdTexture.loadFromFile("Sprites/red.png");
  bird.setTexture(&birdTexture);
}

void Pig::updatepos(sf::Vector2f pos){
  bird.setPosition(pos);
}



