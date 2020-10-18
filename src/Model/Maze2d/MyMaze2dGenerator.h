#pragma once
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include "Position.h"
#include "DFSAlgorithm.h"
#include "Maze2dGenerator.h"
using namespace std;

class Maze2d;

class MyMaze2dGenerator : public Maze2dGenerator
{
public:
    MyMaze2dGenerator() : Maze2dGenerator() {}
    virtual Maze2d &generate(string name, int height);
    virtual void initializeMaze();
    virtual ~MyMaze2dGenerator(){};
};


    // Our maze Structure:
    // row -> col -> bool[0] wall? -> bool[1] visited?
 
 
