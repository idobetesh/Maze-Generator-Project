#include "Maze2dSearchable.h"

Maze2dSearchable::Maze2dSearchable(Maze2d &maze) : m_maze(maze)
{
    for (int i = 0; i < m_maze.getSize(); i++)
    {
        for (int j = 0; j < m_maze.getSize(); j++)
        {
            m_maze.setWall(i, j, 1, 0); // set all slots to unvisited
        }
    }
}

Position &Maze2dSearchable::getStartPosition() { return m_maze.getStartPosition(); }

Position &Maze2dSearchable::getGoalPosition() { return m_maze.getGoalPosition(); }

Maze2d &Maze2dSearchable::getMazeFromSearchable() { return m_maze; }

vector<Position> Maze2dSearchable::getPossibleOptions(Position &p)
{
    return this->convertStringToPosition(m_maze.getPossibleMoves(p), p);
}

vector<Position> Maze2dSearchable::convertStringToPosition(vector<string> possibleMovesString, Position &p)
{
    int pRow, pCol;
    pRow = p.getRow();
    pCol = p.getCol();
    vector<Position> possibleMoves;

    for (auto &posString : possibleMovesString)
    {
        if (posString.compare("UP") == 0)
        {
            Position newPos(pRow - 1, pCol);
            possibleMoves.push_back(newPos);
        }
        if (posString.compare("DOWN") == 0)
        {
            Position newPos(pRow + 1, pCol);
            possibleMoves.push_back(newPos);
        }
        if (posString.compare("RIGHT") == 0)
        {
            Position newPos(pRow, pCol + 1);
            possibleMoves.push_back(newPos);
        }
        if (posString.compare("LEFT") == 0)
        {
            Position newPos(pRow, pCol - 1);
            possibleMoves.push_back(newPos);
        }
    }
    return possibleMoves;
}