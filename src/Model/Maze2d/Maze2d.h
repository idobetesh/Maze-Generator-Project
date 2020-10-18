#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Position.h"

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

class Maze2d
{
private:
    string _mazeName;
    int _mazeSize;
    Position _startPosition;
    Position _goalPosition;
    Position _CurrentPosition;
    vector<vector<vector<bool>>> _maze; // Our maze Structure:
                                        // row -> col -> bool[0] wall? -> bool[1] visited?

public:
    Maze2d() = default;
    Maze2d(string name, int size, Position sP, Position eP, Position cP, vector<vector<vector<bool>>> maze);
    Maze2d(string name, int size, vector<vector<vector<bool>>> maze);
    Maze2d(vector<char> info);
    Maze2d(const Maze2d &maze); //copy constructor
    ~Maze2d(){};

    vector<char> getData() const;
    void setWall(int row, int col, int oneOrZero, bool wall);
    vector<string> getPossibleMoves(Position &p);
    string getMazeName() const;
    vector<vector<vector<bool>>> getMaze() const;
    int getSize();
    Position &getGoalPosition();
    Position &getStartPosition();
    Position &getCurrentPosition();
    void printMaze();
    void setGoalPosition(const Position &goalPos);
    void setStartPosition(const Position &startPos);
    void setCurrentPosition(const Position &currentPos);
    friend std::ostream &operator<<(std::ostream &out, const Maze2d &mz);
};
