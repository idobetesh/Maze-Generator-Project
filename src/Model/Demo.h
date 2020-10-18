#pragma once
#include "MyMaze2dGenerator.h"
#include "BFSAlgorithm.h"
#include "AStarAlgorithm.h"
#include "Adapter.h"
#include "ManhattanHeuristic.h"
#include "AirDistanceHeuristic.h"
#include "MazeCompression.h"

class Demo
{
public:
    void run();
};

void Demo::run()
{
    HeuristicFunc *h_man = new ManhattanHeuristic();
    HeuristicFunc *h_air = new AirDistanceHeuristic();
    BFSAlgorithm *bfs = new BFSAlgorithm(h_man);
    BFSAlgorithm *bfs1 = new BFSAlgorithm(h_air);
    AStarAlgorithm *A = new AStarAlgorithm(h_man);
    AStarAlgorithm *A1 = new AStarAlgorithm(h_air);
    MyMaze2dGenerator *my = new MyMaze2dGenerator();

    cout << "Generating new 2D maze . . .\n";
    Maze2d maze = my->generate("_DEMO_", 31);

    cout << maze << endl;

    Adapter ad(maze);
    Adapter ad1(maze);
    Adapter ad2(maze);
    Adapter ad3(maze);

    Solution sol_bfs = ad.solve2dMaze(bfs);
    Solution sol_bfs1 = ad1.solve2dMaze(bfs1);
    Solution sol_A = ad2.solve2dMaze(A);
    Solution sol_A1 = ad3.solve2dMaze(A1);

    cout << "BFS Manhattan - " << endl;
    cout << ad.getSearchable().getMazeFromSearchable() << endl;
    cout << "Number of states evaluated by BFS is: " << bfs->getNumberOfNodesEvaluated() << endl;
    cout << "BFS AirDistance - " << endl;
    cout << ad1.getSearchable().getMazeFromSearchable() << endl;
    cout << "A* Manhattan - " << endl;
    cout << "Number of states evaluated by BFS is: " << bfs1->getNumberOfNodesEvaluated() << endl;
    cout << ad2.getSearchable().getMazeFromSearchable() << endl;
    cout << "Number of states evaluated by A* is: " << A->getNumberOfNodesEvaluated() << endl;
    cout << "A* AirDistance - " << endl;
    cout << ad3.getSearchable().getMazeFromSearchable() << endl;
    cout << "Number of states evaluated by A* is: " << A1->getNumberOfNodesEvaluated() << endl;

    delete h_man;
    delete h_air;
    delete bfs;
    delete bfs1;
    delete A;
    delete A1;
    delete my;
}