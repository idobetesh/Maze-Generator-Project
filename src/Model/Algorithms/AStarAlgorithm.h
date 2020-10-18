#pragma once
#include "Searcher.h"
#include <queue>

class AStarAlgorithm : public Searcher
{
public:
	AStarAlgorithm(HeuristicFunc *heu) { _heu = heu; }
	virtual Solution search(Searchable &s);
	virtual void runAlgorithm(Maze2d &board){};
	void Fcalculator(Position &pos, int hFromPosition);
	virtual ~AStarAlgorithm(){};
};