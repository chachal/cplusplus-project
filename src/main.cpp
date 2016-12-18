#include <iostream>
#include "game.hpp"

using namespace std;

int main()
{

  //Initiate window, background and music
  sf::RenderWindow win(sf::VideoMode(960, 540), "Angry Birds");
  sf::Sprite background;
  sf::Texture backgroundTex;
  backgroundTex.loadFromFile("Sprites/bg.png");
  background.setTexture(backgroundTex);
  background.setPosition(0,-205);

  sf::Font font;
  font.loadFromFile("Fonts/font.ttf");
  sf::Text text;
  text.setCharacterSize(30);
  text.setStyle(sf::Text::Bold);
  text.setColor(sf::Color::Black);
  text.setFont(font);
  
  sf::Music music;
  if (!music.openFromFile("Audio/music.wav"))
    return -1; // error
  music.setLoop(true);
  music.setVolume(30);
  music.play();
  
  //Loop this until window is closed
  while (win.isOpen()) {
    win.clear();
    win.draw(background);
    win.display();

    //Call Levels
    game(&background, &win, "1");  
    game(&background, &win, "2");
    game(&background, &win, "3");
  }
  return 0;
}


