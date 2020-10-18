#pragma once
#include <vector>
#include "Position.h"

class Maze2d;

class Searchable
{
public:
	virtual Position &getStartPosition() = 0;
	virtual Position &getGoalPosition() = 0;
	virtual vector<Position> getPossibleOptions(Position &s) = 0;
	virtual Maze2d &getMazeFromSearchable() = 0;
};
