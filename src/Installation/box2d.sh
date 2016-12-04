#!/bin/bash

cd 
cd Desktop
wget https://github.com/erincatto/Box2D/archive/master.zip
unzip master.zip
cd Box2D-master/Box2D/Build
cmake -DCMAKE_CXX_FLAGS="-std=c++11" ..
cd Box2D
make
sudo make install
cd 
cd Desktop
rm -rf Box2D-master
rm master.zip


