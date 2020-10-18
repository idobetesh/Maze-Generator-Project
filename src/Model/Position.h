#pragma once
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Position
{
private:
    int _row;
    int _col;
    double h_Cost;
    double g_Cost = 0;
    // int f_Cost = 0;
    Position *_cameFrom;

public:
    Position() = default;
    Position(int x, int y);
    Position(const Position &pos); //copy constructor
    int getRow() const;
    int getCol() const;
    void setPosition(int row, int col);
    void setCameFromPosition(Position* pos); //{ _cameFrom = unique_ptr<Position>(new Position(pos)); }
    Position *getCameFromPosition() const;   ///{ return _cameFrom.get(); }
    double gethCost();
    void sethCost(double cost);
    double getgCost();
    void setgCost(double cost);
    // int getfCost();
    // void setfCost(int cost);
    friend bool operator<(Position &p, Position &otherP);
    bool operator==(const Position &otherP) { return (this->_row == otherP._row && this->_col == otherP._col); }
    friend std::ostream &operator<<(std::ostream &out, const Position &pos);
};