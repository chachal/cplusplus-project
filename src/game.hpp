#include <iostream>
#include "StateMachine.hpp"
#include "GStateMachine.hpp"
#include <SFML/Window.hpp>
#include "birds.hpp"
#include <list>
//#include "levelreader.hpp"
//#include "worldbuilder.hpp"

void createSquares(std::vector<std::pair<RectBody, Bird> >* birds, b2World* world, b2Vec2 pos);
void createCircles(std::vector<std::pair<CircleBody, Bird2> >* birds, b2World* world, b2Vec2 pos);

void game();
