#include "worldbuilder.h"

Worldbuilder::Worldbuilder(string levelNumber)
{
	std::vector<std::vector<std::vector<float> > > levelData = levelReader(levelNumber);
	auto it = levelData.begin();
	for (auto birds = it->begin(); birds != it->end(); birds++) {
		auto bird = birds->begin();
		int quant = *bird;
		bird++;
		int type = *bird;
		for (int i = 0; i < quant; i++) {
			Bird b;
			b.init(sf::Vector2f(10.0f, 10.0f), sf::Vector2f(10.0f, 10.0f), type);
			m_birds.push_back(b);
		}
	}
	it++;
	for (auto blocks = it->begin(); blocks != it->end(); blocks++) {
		auto block = blocks->begin();
		int type = *block;
		block++;
		float angle = *block;
		block++;
		float x = *block;
		block++;
		float y = *block;
		Block b;
		b.init(sf::Vector2f(x, y), type, angle);
		m_blocks.push_back(b);
	}
	it++;
	for (auto pigs = it->begin(); pigs != it->end(); pigs++) {
		auto pig = pigs->begin();
		int type = *pig;
		pig++;
		float x = *pig;
		pig++;
		float y = *pig;
		Pig b;
		b.init(sf::Vector2f(x, y), type);
		m_pigs.push_back(b);
	}
}


Worldbuilder::~Worldbuilder()
{

}

void Worldbuilder::Draw(sf::RenderWindow &win)
{
	for (auto it = m_blocks.begin(); it != m_blocks.end(); it++) {
		win.draw((*it).block);
	}
	for (auto it = m_pigs.begin(); it != m_pigs.end(); it++) {
		win.draw((*it).pig);
	}
}