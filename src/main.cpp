#include <iostream>
#include "StateMachine.hpp"
#include "GStateMachine.hpp"
#include "game.hpp"

using namespace std;

int main()
{
  sf::RenderWindow win(sf::VideoMode(960, 540), "Angry Birds");
  sf::Sprite background;
  sf::Texture backgroundTex;
  backgroundTex.loadFromFile("Sprites/bg.png");
  background.setTexture(backgroundTex);
  background.setPosition(0,-205);

  sf::Font font;
  font.loadFromFile("font.ttf");
  sf::Text text;
  text.setCharacterSize(30);
  text.setStyle(sf::Text::Bold);
  text.setColor(sf::Color::Black);
  text.setFont(font);
  


  sf::Music music;
  if (!music.openFromFile("music.wav"))
    return -1; // error
  music.setLoop(true);
  music.setVolume(30);
  music.play();
  while (win.isOpen()) {
    win.clear();
    win.draw(background);
    win.display();
    game(&background, &win, "1");
    game(&background, &win, "2");
    game(&background, &win, "3");
  }
  return 0;
}


