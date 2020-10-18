#pragma once
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include "MyMaze2dGenerator.h"
#include "SimpleMaze2dGenerator.h"
#include "Maze2dSearchable.h"
#include "BFSAlgorithm.h"
#include "AStarAlgorithm.h"

class TestMazeGenerator
{
public:
    TestMazeGenerator() = default;

    void TestMazeGeneratorGenerator(Maze2dGenerator &mg)
    {
        cout << "Time took to generate this maze: " << mg.measureAlgorithmTime(31) << endl;

        Maze2d maze = mg.generate("test", 31);

        Position p = maze.getStartPosition();

        cout << "start position: " << p << endl;
        cout << "goal position: " << maze.getGoalPosition() << endl;

        vector<string> moves = maze.getPossibleMoves(p);

        cout << "possible directions: [ ";
        for (auto move : moves)
            cout << move << " ";
        cout << "]" << endl;

        cout << "\n" << maze << endl;
    }

    ~TestMazeGenerator(){};
};
