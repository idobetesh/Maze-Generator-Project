#include "MyMaze2dGenerator.h"

// initialize the maze vector
void MyMaze2dGenerator::initializeMaze()
{
    for (int i = 0; i < _mazeSize[1]; i++) // i < _maz eWidth
    {
        for (int j = 0; j < _mazeSize[0]; j++) // j < _mazeHeight
        {
            bool endOfBoard;

            if (i == 0 || i == _mazeSize[1] - 1 || j == 0 || j == _mazeSize[0] - 1) // any border of the board
                endOfBoard = true;
            else
                endOfBoard = false;

            vector<bool> cube = {true, endOfBoard};

            if (i + 1 > maze.size())
            {
                vector<vector<bool>> new_row = {cube};
                maze.push_back(new_row);
            }
            else
                maze[i].push_back(cube);
        }
    }
}

Maze2d &MyMaze2dGenerator::generate(string name, int height)
{
    _crtAlgo = new DFSAlgorithm();
    _mazeName = name;

    _mazeSize[0] = height;
    _mazeSize[1] = height;
    this->initializeMaze();
    Maze2d *newMaze = new Maze2d(_mazeName, _mazeSize[0], maze);

    _crtAlgo->runAlgorithm(*newMaze);

    //this->randomPoint(false); //dfs|
    //this->generateMaze();     //dfs|---> runAlgorithm
    //this->randomPoint(true);  //dfs|

    return *newMaze;
}
