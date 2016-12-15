#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <stdlib.h>

using namespace std;

vector<vector<vector<float> > > levelReader(string levelNumber) {
  string levelFile = "levels/" + levelNumber + ".csv";
  vector<vector<float> > birds, blocks, pigs;
  vector<vector<vector<float> > > levelData;
  string line, data;
  float tmp;
  ifstream level;
  level.open(levelFile.c_str());
  if (level.is_open()) {
    while (!level.eof()) {
      getline(level, line);
      stringstream sline(line);
      getline(sline, data, ',');
      if (data == "bird") {
        vector<float> onebird;
        for (int i = 0; i < 2; i++) {
          getline(sline, data, ',');
          tmp = atof(data.c_str());
          onebird.push_back(tmp);
        }
        birds.push_back(onebird);
        onebird.clear();
      }
      else if (data == "block") {
        vector<float> oneblock;
        for (int i = 0; i < 3; i++) {
          getline(sline, data, ',');
          tmp = atof(data.c_str());
          oneblock.push_back(tmp);
        }
        blocks.push_back(oneblock);
        oneblock.clear();
      }
      else if (data == "pig") {
        vector<float> onepig;
        for (int i = 0; i < 2; i++) {
          getline(sline, data, ',');
          tmp = atof(data.c_str());
          onepig.push_back(tmp);
        }
        pigs.push_back(onepig);
        onepig.clear();
      }
    }
    levelData.push_back(birds);
    levelData.push_back(blocks);
    levelData.push_back(pigs);
  }
  else {
    float z = 0;
    vector<float> zer;
    vector<vector<float> > zero;
    zer.push_back(z);
    zero.push_back(zer);
    levelData.push_back(zero);
  }
  level.close();
  return levelData;
}
