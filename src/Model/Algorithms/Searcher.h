#pragma once
#include "Solution.h"
#include "Searchable.h"
#include "Algorithm.h"
#include "Position.h"
#include "AirDistanceHeuristic.h"
#include "ManhattanHeuristic.h"
#include <queue>

struct LessThanByCost // priority_queue function
{
	bool operator()(Position &p, Position &p1)
	{
		return p.gethCost() > p1.gethCost();
	}
};

class Searcher : public Algorithm
{
protected:
	HeuristicFunc *_heu;
	int m_evaluatedNodes = 0;
	priority_queue<Position, vector<Position>, LessThanByCost> m_openList;

public:
	virtual Solution search(Searchable &s) = 0;
	virtual void runAlgorithm(Maze2d &board) = 0;
	virtual int getNumberOfNodesEvaluated();
	const Position &popOpenList();
	virtual ~Searcher(){};
};
