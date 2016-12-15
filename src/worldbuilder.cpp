#include "worldbuilder.hpp"

void createObjects(std::vector<std::pair<RectBody, Bird> >* birds, b2World* world, b2Vec2 pos)
{
  RectBody a;
  Bird b;
  a.init(world, pos);    
  b.init();
  birds->push_back(std::make_pair(a,b));
}
void createObjects(std::vector<std::pair<CircleBody, Bird2> >* birds, b2World* world, b2Vec2 pos)
{
  CircleBody a;
  Bird2 b;
  a.init(world, pos);    
  b.init();
  birds->push_back(std::make_pair(a,b));
}

void createObjects(std::vector<std::pair<CircleBody, Pig> >* birds, b2World* world, b2Vec2 pos)
{
  CircleBody a;
  Pig b;
  a.init(world, pos);    
  b.init();
  birds->push_back(std::make_pair(a,b));
}


void Worldbuilder(string levelNumber, b2World* world, std::vector<std::pair<RectBody, Bird> >* v_blocks, std::vector<std::pair<CircleBody, Pig> >* v_pigs)
{
  std::vector<std::vector<std::vector<float> > > levelData = levelReader(levelNumber);
  std::vector<std::pair<CircleBody, Bird2> > v_birds;
  
  auto it = levelData.begin();
  for (auto birds = it->begin(); birds != it->end(); birds++) {
    auto bird = birds->begin();
    int quant = *bird;
    bird++;
    int type = *bird;
    for (int i = 0; i < quant; i++) {
      createObjects(&v_birds, world, b2Vec2 (1.0f, 1.0f));
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
    createObjects(v_blocks, world, b2Vec2 (x,y));
  }
  it++;
  for (auto pigs = it->begin(); pigs != it->end(); pigs++) {
    auto pig = pigs->begin();
    int type = *pig;
    pig++;
    float x = *pig;
    pig++;
    float y = *pig;
    createObjects(v_pigs, world, b2Vec2 (x,y));
  }
}

