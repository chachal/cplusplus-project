#include <iostream>
#include "birds.hpp"

void Box::init(){

  bird.setSize(sf::Vector2f(70.0f, 70.0f));
  bird.setRotation(0.f);
  bird.setOrigin(33.f, 28.f);
  bird.setPosition(0,0);
  birdTexture.loadFromFile("Sprites/box.png");
  birdTexture.setSmooth(true);
  bird.setTexture(&birdTexture);
    
}

void Box::updatepos(sf::Vector2f pos){
  bird.setPosition(pos);
}


void Bird::init(){
  bird.setRadius(35.0f);
  bird.setRotation(0.f);
  bird.setOrigin(35.f, 35.f);
  bird.setPosition(0,0);
  birdTexture.loadFromFile("Sprites/red.png");
  birdTexture.setSmooth(true);
  bird.setTexture(&birdTexture);

}

void Bird::updatepos(sf::Vector2f pos){
  bird.setPosition(pos);
}


void Pig::init(){
  bird.setRadius(30.0f);
  bird.setRotation(0.f);
  bird.setOrigin(30.f, 30.f);
  bird.setPosition(0,0);
  birdTexture.loadFromFile("Sprites/pig.png");
  birdTexture.setSmooth(true);
  bird.setTexture(&birdTexture);
}

void Pig::updatepos(sf::Vector2f pos){
  bird.setPosition(pos);
}



