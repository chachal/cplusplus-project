#include <iostream>
#include "GStateMachine.hpp"
#include <SFML/Graphics.hpp>

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
  sf::RenderWindow win(sf::VideoMode(100, 100), "Angry Birds", sf::Style::Default);
  while (1) {
    /* code */
  }
    event_loop();
}
