#pragma once
#include <stdlib.h>
#include <vector>
#include <list>
#include "graphics.h"

class worldbuilder
{
public:
	worldbuilder(std::vector<std::vector<std::vector<float> > > levelData);
	~worldbuilder();
private:
	std::vector<Bird> m_birds;
	std::vector<Block> m_blocks;
	std::vector<Pig> m_pigs;
};
