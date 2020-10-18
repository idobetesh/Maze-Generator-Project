#pragma once
#include "Algorithm.h"

class CreateAlgorithm : public Algorithm
{
public:
    CreateAlgorithm() = default;
    virtual void runAlgorithm(Maze2d &board) = 0;
    virtual void generateMaze(Maze2d &board) = 0;
    virtual ~CreateAlgorithm() {};
};