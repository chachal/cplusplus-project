#include <iostream>
#include "StateMachine.hpp"
#include "GStateMachine.hpp"
#include "game.hpp"

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
  game();
  event_loop();
  return 0;
}


