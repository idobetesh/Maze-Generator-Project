#pragma once
#include "Searcher.h"
#include <queue>

class BFSAlgorithm : public Searcher
{
public:
	BFSAlgorithm(HeuristicFunc *heu) { _heu = heu; }
	virtual Solution search(Searchable &s);
	virtual void runAlgorithm(Maze2d &board){};
	virtual ~BFSAlgorithm(){};
};
