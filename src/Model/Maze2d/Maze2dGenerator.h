#pragma once
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include "Position.h"
#include "Maze2d.h"
#include "DFSAlgorithm.h"
#include "SimpleCrtAlgorithm.h"
using namespace std;

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

class CreateAlgorithm;
class Maze2d;

class Maze2dGenerator
{
protected:
    CreateAlgorithm *_crtAlgo;
    string _mazeName;
    int _mazeSize[2];
    vector<vector<vector<bool>>> maze;

public:
    Maze2dGenerator() = default;
    virtual Maze2d &generate(string name, int height) = 0;
    virtual string measureAlgorithmTime(int size);
    virtual void initializeMaze() = 0;
    virtual ~Maze2dGenerator(){};
};
