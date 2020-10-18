#pragma once
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include "Position.h"
#include "SimpleCrtAlgorithm.h"
#include "Maze2dGenerator.h"
using namespace std;

class Maze2d;

class SimpleMaze2dGenerator : public Maze2dGenerator
{
public:
    SimpleMaze2dGenerator() : Maze2dGenerator() {}
    virtual Maze2d &generate(string name, int height); 
    virtual void initializeMaze(); 
    virtual ~SimpleMaze2dGenerator(){}; 
};