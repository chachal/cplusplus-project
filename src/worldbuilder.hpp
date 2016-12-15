#pragma once
#include <stdlib.h>
#include <vector>
#include <list>
#include "birds.hpp"
#include "levelreader.hpp"

class Worldbuilder
{
public:
  Worldbuilder(string levelNumber);
  ~Worldbuilder();
  void Draw(sf::RenderWindow &win);
private:
  std::vector<Bird> m_birds;
  std::vector<Block> m_blocks;
  std::vector<Pig> m_pigs;
};
