#pragma once
#include "Maze2d.h"
#include <math.h>

class HeuristicFunc
{
protected:
    double _sum;

public:
    HeuristicFunc() = default;
    virtual double calculateHeuristic(Position &pos, Maze2d& maze) = 0;
    virtual ~HeuristicFunc(){};
};