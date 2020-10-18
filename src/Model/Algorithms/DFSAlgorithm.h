#pragma once
#include <vector>
#include "CreateAlgorithm.h"

class DFSAlgorithm : public CreateAlgorithm
{
private:
    int start_pivot;
    int start_side;
    vector<vector<int>> dfs_path;

public:
    DFSAlgorithm() = default;
    virtual void runAlgorithm(Maze2d &board);
    virtual void generateMaze(Maze2d &board);
    void randomPoint(bool part, Maze2d &board); 
    bool randomMove(bool isFirstMove, Maze2d &board);
    virtual ~DFSAlgorithm(){};
};
