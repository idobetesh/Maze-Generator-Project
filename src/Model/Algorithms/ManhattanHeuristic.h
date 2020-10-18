#pragma once
#include "HeuristicFunc.h"

class ManhattanHeuristic : public HeuristicFunc
{
public:
    virtual double calculateHeuristic(Position &pos, Maze2d& maze)
    {
        _sum = 0;
        _sum = (abs(maze.getGoalPosition().getRow() - pos.getRow())) + abs((maze.getGoalPosition().getCol() - pos.getCol()));
        return _sum;
    }
    virtual ~ManhattanHeuristic(){};
};