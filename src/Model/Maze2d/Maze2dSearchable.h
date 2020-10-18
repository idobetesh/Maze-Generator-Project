#pragma once
#include "Searchable.h"
#include "Maze2d.h"
#include <math.h>

class Maze2dSearchable : public Searchable
{
protected:
	Maze2d m_maze;

public:
	Maze2dSearchable(Maze2d &maze);

	virtual Position &getStartPosition();
	virtual Position &getGoalPosition();
	virtual vector<Position> getPossibleOptions(Position &p);
	virtual Maze2d &getMazeFromSearchable();
	vector<Position> convertStringToPosition(vector<string> possibleMovesString, Position &p);
};
