#pragma once
#include "HeuristicFunc.h"

class AirDistanceHeuristic : public HeuristicFunc
{
public:
    virtual double calculateHeuristic(Position &pos, Maze2d &maze)
    {
        int rowSum = 0;
        int colSum = 0;
        rowSum = abs(maze.getGoalPosition().getRow() - pos.getRow());
        colSum = abs(maze.getGoalPosition().getCol() - pos.getCol());
        _sum = sqrt(pow(rowSum, 2) + pow(colSum, 2));
        return _sum;
    }
    virtual ~AirDistanceHeuristic(){};
};