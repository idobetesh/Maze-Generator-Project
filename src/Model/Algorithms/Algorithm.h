#pragma once
#include <vector>
#include "Maze2d.h"

class Maze2d;

class Algorithm
{
public:
    Algorithm() = default;
    virtual void runAlgorithm(Maze2d &board) = 0;
    virtual ~Algorithm(){};
};
