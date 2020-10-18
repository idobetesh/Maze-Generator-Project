#pragma once
#include "Maze2dSearchable.h"
#include "Solution.h"
#include "Searcher.h"

class Adapter
{
private:
    Searchable *_s;

public:
    Adapter(Maze2d maze)
    {
        _s = new Maze2dSearchable(maze);
    }
    Solution solve2dMaze(Searcher *lookFor)
    {
        return lookFor->search(*_s);
    }
    Searchable &getSearchable() { return *_s; }
    virtual ~Adapter() { delete _s; };
};