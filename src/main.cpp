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
  sf::RenderWindow win(sf::VideoMode(960, 540), "Angry Birds");
  Bird a;
  a.init(sf::Vector2f(63.0f, 65.0f), sf::Vector2f(50.0f, 50.0f));
  sf::Clock kello;
  sf::Clock kello2;

  while (win.isOpen()) {
    float d = kello2.restart().asSeconds();
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
    int delta = kello.getElapsedTime().asMilliseconds();
    a.updateanim(d);
    if (delta > 1000/60) {
      kello.restart();
      a.updatepos();
      win.clear();
      win.draw(a.bird);
      win.display();

    }
    
  }
    event_loop();
    return 0;

}
