#include "SimpleMaze2dGenerator.h"

void SimpleMaze2dGenerator::initializeMaze()
{
    maze.resize(_mazeSize[0]);
    for (int i = 0; i < maze.size(); i++)
        maze[i].resize(_mazeSize[1]);

    for (int i = 0; i < maze.size(); i++)
        for (int j = 0; j < maze[i].size(); j++)
            maze[i][j].resize(2);

    for (int i = 0; i < maze.size(); i++)
    {
        for (int j = 0; j < maze[i].size(); j++)
        {
            if (i == 0 || j == 0 || i == maze.size() - 1 || j == maze.size() - 1) // build maze frame
                maze[i][j][0] = true;
            else
                maze[i][j][0] = false;
        }
    }
}

Maze2d &SimpleMaze2dGenerator::generate(string name, int height)
{
    _crtAlgo = new SimpleCrtAlgorithm();
    _mazeName = name;

    _mazeSize[0] = height;
    _mazeSize[1] = height;
    this->initializeMaze();
    Maze2d *newMaze = new Maze2d(_mazeName, _mazeSize[0], maze);

    _crtAlgo->runAlgorithm(*newMaze);

    return *newMaze;
}