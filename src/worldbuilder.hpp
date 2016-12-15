#pragma once
#include <stdlib.h>
#include <vector>
#include <list>
#include "birds.hpp"
#include "levelreader.hpp"

void Worldbuilder(string levelNumber, b2World* world, std::vector<std::pair<RectBody, Bird> >* v_blocks, std::vector<std::pair<CircleBody, Pig> >* v_pigs, std::vector<std::pair<CircleBody, Bird2> >* v_birds);
void createObjects(std::vector<std::pair<RectBody, Bird> >* birds, b2World* world, b2Vec2 pos);
void createObjects(std::vector<std::pair<CircleBody, Bird2> >* birds, b2World* world, b2Vec2 pos);
void createObjects(std::vector<std::pair<CircleBody, Pig> >* birds, b2World* world, b2Vec2 pos);
