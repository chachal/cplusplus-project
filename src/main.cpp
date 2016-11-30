#include <iostream>
#include "StateMachine.hpp"
#include "GStateMachine.hpp"
#include <SFML/Window.hpp>
#include "graphics.hpp"

using namespace std;

static void event_loop()
{
    int mode = 0;
    //mode 1 == pelissä, tähän voi lisäillä modeja menuun mitä haluaa
    //mainin piirto
    //keylistenerit / mouse listener millä vaihdetaan tota modea sfml avulla että pääsee peliin
    // jos modeja tulee enemmän niin vaihtaa ton if silmukan switchiksi, jne.
    if (mode != 0){


    }


}

int main()
{
  cout<<"STARTING"<<endl;
  sf::RenderWindow win(sf::VideoMode(800, 600), "Angry Birds");
  Bird a;
  a.init(sf::Vector2f(63.0f, 65.0f), sf::Vector2f(50.0f, 50.0f));
  sf::Clock kello;

  while (1) {
    int delta = kello.getElapsedTime().asMilliseconds();
    if (delta > 1000/60) {
      kello.restart();
      a.updatepos();
    }
    
  }
    event_loop();
    return 0;

}
