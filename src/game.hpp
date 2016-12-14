#include <iostream>
#include "StateMachine.hpp"
#include "GStateMachine.hpp"
#include <SFML/Window.hpp>
#include "graphics.hpp"
#include <list>

void createObjects(std::vector<std::pair<RectBody, Bird> >* birds, b2World* world, b2Vec2 pos);

void game();
