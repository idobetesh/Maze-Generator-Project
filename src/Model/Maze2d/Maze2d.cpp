#include "Maze2d.h"
#include <sstream>
#include <string>
#include <cstring>

Maze2d::Maze2d(string name, int size, Position sP, Position eP, Position cP, vector<vector<vector<bool>>> maze)
    : _mazeName(name), _mazeSize(size), _startPosition(sP), _goalPosition(eP), _CurrentPosition(cP), _maze(maze) {}

Maze2d::Maze2d(string name, int size, vector<vector<vector<bool>>> maze)
    : _mazeName(name), _mazeSize(size), _maze(maze) {}

Maze2d::Maze2d(const Maze2d &maze) //copy constructor
{
    _mazeName = maze._mazeName;
    _startPosition = maze._startPosition;
    _goalPosition = maze._goalPosition;
    _CurrentPosition = maze._CurrentPosition;
    _mazeSize = maze._mazeSize;

    _maze.resize(_mazeSize);
    for (int i = 0; i < _mazeSize; i++)
    {
        _maze[i].resize(_mazeSize);
    }
    for (int i = 0; i < _mazeSize; i++)
        for (int j = 0; j < _mazeSize; j++)
        {
            _maze[i][j].resize(2);
        }

    for (int i = 0; i < _mazeSize; i++)
    {
        for (int j = 0; j < _mazeSize; j++)
        {
            for (int k = 0; k < 2; k++)
                _maze[i][j][k] = maze.getMaze()[i][j][k];
        }
    }
}

void Maze2d::setWall(int row, int col, int oneOrZero, bool wall)
{
    _maze[row][col][oneOrZero] = wall;
}

string Maze2d::getMazeName() const
{
    return _mazeName;
}
vector<vector<vector<bool>>> Maze2d::getMaze() const
{
    return _maze;
}

void Maze2d::printMaze()
{
    cout << *this;
}

int Maze2d::getSize()
{
    return _mazeSize;
}

Position &Maze2d::getGoalPosition()
{
    return _goalPosition;
}

Position &Maze2d::getStartPosition()
{
    return _startPosition;
}

Position &Maze2d::getCurrentPosition()
{
    return _CurrentPosition;
}
void Maze2d::setGoalPosition(const Position &goalPos)
{
    _goalPosition = goalPos;
}

void Maze2d::setStartPosition(const Position &startPos)
{
    _startPosition = startPos;
}

void Maze2d::setCurrentPosition(const Position &currentPos)
{
    _CurrentPosition = currentPos;
}

std::ostream &operator<<(std::ostream &out, const Maze2d &mz)
{
    // cout <<  "\t" << _mazeName << endl;
    for (int i = 0; i < mz._mazeSize; i++)
    {
        for (int j = 0; j < mz._mazeSize; j++)
        {
            if (mz._maze[i][j][false]) //wall
                out << "{}";
            else if (mz._maze[i][j][true]) //solution path
                out << "++";
            else
                out << "  "; //path
        }
        out << endl;
    }
    return out;
}

vector<string> Maze2d::getPossibleMoves(Position &p)
{
    int row = p.getRow();
    int col = p.getCol();
    vector<string> possibleMoves;

    if (_maze[row][col][0])
    {
        possibleMoves.push_back("BLOCK!");
        return possibleMoves;
    }

    if (row + 1 < _mazeSize - 1)
    {
        if (!_maze[row + 1][col][0])
            possibleMoves.push_back("DOWN");
    }
    if (row - 1 > 0)
    {
        if (!_maze[row - 1][col][0])
            possibleMoves.push_back("UP");
    }

    if (col < _mazeSize - 2)
    {
        if (!_maze[row][col + 1][0])
            possibleMoves.push_back("RIGHT");
    }

    if (col > 1)
    {
        if (!_maze[row][col - 1][0])
            possibleMoves.push_back("LEFT");
    }

    return possibleMoves;
}

string tostr(int x)
{
    std::stringstream str;
    str << x;
    return str.str();
};

void convertToCharAndPush(vector<char> &data, int number)
{
    string s = tostr(number);
    int num = s.length();
    data.push_back('0' + num);
    for (int j = 0; j < s.length(); j++)
        data.push_back(s[j]);
}

vector<char> Maze2d::getData() const
{
    vector<char> data; // the vector with the details
    convertToCharAndPush(data, _mazeSize);
    convertToCharAndPush(data, _startPosition.getRow());
    convertToCharAndPush(data, _startPosition.getCol());
    convertToCharAndPush(data, _goalPosition.getRow());
    convertToCharAndPush(data, _goalPosition.getCol());

    for (int i = 0; i < _mazeSize; i++)
    {
        for (int j = 0; j < _mazeSize; j++)
        {
            if (_maze[i][j][0] == true)
                data.push_back('A');
            if (_maze[i][j][0] == false)
                data.push_back('B');
            if (_maze[i][j][1] == true)
                data.push_back('C');
            if (_maze[i][j][1] == false)
                data.push_back('D');
        }
    }
    return data;
}

Maze2d::Maze2d(vector<char> info) //vector<char> {_mazeSize, startPos, goalPos, maze content}
{
    int nume = *info.begin() - '0'; // the number of digits of the size
    auto it = info.begin();
    it++; // get to the
    int sizeOfNum = *it - '0';
    for (int j = 1; j < nume; j++)
    {
        it++;
        sizeOfNum = sizeOfNum * 10 + *it - '0';
    }
    it++;

    _mazeSize = sizeOfNum; // GET THE MAZE SIZE

    int startR = 0;
    int startC = 0;
    int goalR = 0;
    int goalC = 0;

    nume = *it - '0';
    it++;
    sizeOfNum = *it - '0';
    for (int i = 1; i < nume; i++)
    {
        it++;
        sizeOfNum = sizeOfNum * 10 + *it - '0';
    }
    it++;
    startR = sizeOfNum;
    nume = *it - '0';
    it++;
    sizeOfNum = *it - '0';
    for (int i = 1; i < nume; i++)
    {
        it++;
        sizeOfNum = sizeOfNum * 10 + *it - '0';
    }
    it++;
    startC = sizeOfNum;

    nume = *it - '0';
    it++;
    sizeOfNum = *it - '0';
    for (int i = 1; i < nume; i++)
    {
        it++;
        sizeOfNum = sizeOfNum * 10 + *it - '0';
    }
    it++;
    goalR = sizeOfNum;

    nume = *it - '0';
    it++;
    sizeOfNum = *it - '0';
    for (int i = 1; i < nume; i++)
    {
        it++;
        sizeOfNum = sizeOfNum * 10 + *it - '0';
    }
    it++;
    goalC = sizeOfNum;

    _startPosition.setPosition(startR, startC);
    _goalPosition.setPosition(goalR, goalC);

    _maze.resize(_mazeSize); // resizing the maze
    for (int i = 0; i < _mazeSize; i++)
    { // resizing the maze
        _maze[i].resize(_mazeSize);
    }

    for (int j = 0; j < _mazeSize; j++)
    {
        for (int i = 0; i < _mazeSize; i++)
        {
            _maze[j][i].resize(2);
        }
    }

    int cnt = 0;
    for (int i = 0; i < _mazeSize; i++)
    {
        for (int j = 0; j < _mazeSize; j++)
        {
            if (*(it + cnt) == 'A')
                setWall(i, j, 0, 1);
            if (*(it + cnt) == 'B')
                setWall(i, j, 0, 0);
            cnt++;
            if (*(it + cnt) == 'C')
                setWall(i, j, 1, 1);
            if (*(it + cnt) == 'D')
                setWall(i, j, 1, 0);
            cnt++;
        }
    }
}
