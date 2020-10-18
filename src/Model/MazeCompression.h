#pragma once
#include <unordered_map>
#include "Maze2d.h"
#include <fstream>

class MazeComperssion
{
private:
    Maze2d maze;

public:
    MazeComperssion() = default;
    MazeComperssion(Maze2d m);
    string compress(vector<char> &data) const;
    vector<char> decompress(string data);
    void save(ofstream &out_file) const;
    Maze2d &load(ifstream &in_file);
    // Maze2d getLodedMaze() { return maze; }
    ~MazeComperssion(){};
};