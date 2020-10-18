#pragma once
#include <vector>
#include "CreateAlgorithm.h"

#define S_DOWN 0
#define S_RIGHT 1

class Maze2d;

class SimpleCrtAlgorithm : public CreateAlgorithm
{
public:
    SimpleCrtAlgorithm() = default;
    virtual void runAlgorithm(Maze2d &board);
    virtual void generateMaze(Maze2d &board);
    virtual ~SimpleCrtAlgorithm(){};
};
