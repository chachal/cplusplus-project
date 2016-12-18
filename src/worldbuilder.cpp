#include "worldbuilder.hpp"

//Creation methods for objects
void createObjects(std::vector<std::pair<RectBody, Box> >* birds, b2World* world, b2Vec2 pos)
{
  RectBody a;
  Box b;
  a.init(world, pos);    
  birds->push_back(std::make_pair(a,b));
}
void createObjects(std::vector<std::pair<CircleBody, Bird> >* birds, b2World* world, b2Vec2 pos)
{
  CircleBody a;
  Bird b;
  a.init(world, pos);    
  birds->push_back(std::make_pair(a,b));
}

void createObjects(std::vector<std::pair<CircleBody, Pig> >* birds, b2World* world, b2Vec2 pos)
{
  CircleBody a;
  Pig b;
  a.init(world, pos);    
  birds->push_back(std::make_pair(a,b));
}


//Build the gameworld with creation methods
void Worldbuilder(string levelNumber, b2World* world, std::vector<std::pair<RectBody, Box> >* v_blocks, std::vector<std::pair<CircleBody, Pig> >* v_pigs, std::vector<std::pair<CircleBody, Bird> >* v_birds2)
{
  //Pass levelnumber to levelreader method
  std::vector<std::vector<std::vector<float> > > levelData = levelReader(levelNumber);
  auto it = levelData.begin();

  //Iterate over the found data and call creation functions for objects
  for (auto birds = it->begin(); birds != it->end(); birds++) {
    auto bird = birds->begin();
    bird++;
    createObjects(v_birds2, world, b2Vec2(190/30.f, 370/30.f));

  }
  it++;
  for (auto blocks = it->begin(); blocks != it->end(); blocks++) {
    auto block = blocks->begin();
    block++;
    block++;
    float x = *block;
    block++;
    float y = *block;
    createObjects(v_blocks, world, b2Vec2 (x,y));
  }
  it++;
  for (auto pigs = it->begin(); pigs != it->end(); pigs++) {
    auto pig = pigs->begin();
    pig++;
    float x = *pig;
    pig++;
    float y = *pig;
    createObjects(v_pigs, world, b2Vec2 (x,y));
  }
}

