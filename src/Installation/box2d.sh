#!/bin/bash

sudo apt-get install g++ cmake libglu-dev libxi-dev
cd ..
wget https://github.com/erincatto/Box2D/archive/master.zip
unzip master.zip
cd Box2D-master/Box2D/Build
cmake -DCMAKE_CXX_FLAGS="-std=c++11" ..
cd Box2D
make
sudo make install INSTALL_ROOT=$/home/libs/
cd ../../..
rm -rf Contributions
cd ..
rm master.zip


