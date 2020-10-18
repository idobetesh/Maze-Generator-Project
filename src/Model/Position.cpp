#include "Position.h"

Position::Position(int x, int y) : _row(x), _col(y) {}

Position::Position(const Position &pos)
{
    _row = pos.getRow();
    _col = pos.getCol();
    h_Cost = pos.h_Cost;
    g_Cost = pos.g_Cost;
    _cameFrom = pos._cameFrom;
}

int Position::getRow() const
{
    return _row;
}
int Position::getCol() const
{
    return _col;
}
void Position::setPosition(int row, int col)
{
    _row = row;
    _col = col;
}

void Position::setCameFromPosition(Position *pos)
{
    _cameFrom = pos;
}

Position *Position::getCameFromPosition() const { return _cameFrom; } ///{ return _cameFrom.get(); }

double Position::gethCost() { return h_Cost; }

void Position::sethCost(double cost) { h_Cost = cost; }

double Position::getgCost() { return g_Cost; }

void Position::setgCost(double cost) { g_Cost = cost; }

//int Position::getfCost() { return f_Cost; }

//void Position::setfCost(int cost) { f_Cost = cost; }

std::ostream &operator<<(std::ostream &out, const Position &pos)
{
    out << "{" << pos._row << ", " << pos._col << "}";
    return out;
}

bool operator<(Position &p, Position &otherP) { return p.gethCost() < otherP.gethCost(); }