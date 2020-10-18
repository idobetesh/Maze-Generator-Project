#pragma once
#include <unordered_map>
#include "Maze2d.h"
#include "Solution.h"
#include "MyMaze2dGenerator.h"
#include "BFSAlgorithm.h"
#include "AStarAlgorithm.h"
#include "ManhattanHeuristic.h"
#include "AirDistanceHeuristic.h"
#include "Maze2dSearchable.h"
#include "MazeCompression.h"
#include "Adapter.h"

struct WrongAlgorithmName
{
};
struct WrongMazeName
{
};

class Model
{
private:
    unordered_map<string, pair<Maze2d *, Solution *>> _cache;

public:
    ~Model();
    void generate(string name, int size);
    void solve(string name, string algoName);
    void save(string name, string fileName);
    void load(string fileName, string name);
    void display(string name);
    void displaySolution(string name);
    void getMazeSize(string name);
};