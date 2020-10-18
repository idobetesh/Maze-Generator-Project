#include "DFSAlgorithm.h"

void DFSAlgorithm::runAlgorithm(Maze2d &board)
{
    this->randomPoint(false, board); //board.getSize());
    this->randomPoint(true, board);  //board.getSize());
    this->generateMaze(board);
}

void DFSAlgorithm::randomPoint(bool part, Maze2d &board)
{
    int size = board.getSize();
    int _mazeSize[2] = {size, size};
    int pivot, side;
    if (!part)
    {
        pivot = rand() % 2; // between 0-1
        side = rand() % 2;
        start_pivot = pivot;
        start_side = side;
    }
    else
    {
        bool done = false;
        while (!done)
        {
            pivot = rand() % 2;
            side = rand() % 2;

            if (pivot != start_pivot || side != start_side)
                done = true;
        }
    }

    vector<int> position = {0, 0};
    
    if (!side)
        position[!pivot] = 0;
    else
        position[!pivot] = _mazeSize[!pivot] - 1;

    position[pivot] = 2 * (rand() % ((_mazeSize[pivot] + 1) / 2 - 2)) + 1; // randomly generate value to position[pivot]

    if (!part)
        dfs_path.push_back(position);

    if (!part) // set start and end positions
    {
        Position tmpStart(position[0], position[1]);
        board.setStartPosition(tmpStart);
        board.setCurrentPosition(tmpStart);
    }
    else
    {
        Position tmpGoal(position[0], position[1]);
        board.setGoalPosition(tmpGoal);
    }

    board.setWall(position[0], position[1], 1, 1);
    board.setWall(position[0], position[1], 0, 0);
}

void DFSAlgorithm::generateMaze(Maze2d &board)
{
    bool isFirstMove = true;
    bool success = true;

    while (dfs_path.size() > 1 - isFirstMove)
    {
        if (!success)
        {
            dfs_path.pop_back();
            if (!isFirstMove && dfs_path.size() > 2)
                dfs_path.pop_back();
            else
                break;

            success = true;
        }
        while (success)
        {
            success = randomMove(isFirstMove, board);
            if (isFirstMove)
                isFirstMove = false;
        }
    }
        for (int i = 0; i < board.getSize(); i++)
       {
            for (int j = 0; j < board.getSize(); j++)
            {
                board.setWall(i, j, 1, 0); // set all slots to unvisited
            }
        }
}

bool DFSAlgorithm::randomMove(bool isFirstMove, Maze2d &board)
{
    int randomNeighbor;
    vector<vector<int>> unvisitedNeighbors;
    for (int direction = 0; direction < 4; direction++)
    {
        int possibleMoveDirection[2] = {0, 0}; //{x,y}

        if (direction == UP)
            possibleMoveDirection[1] = -1;
        else if (direction == DOWN)
            possibleMoveDirection[1] = 1;
        else if (direction == LEFT)
            possibleMoveDirection[0] = -1;
        else //direction == RIGHT
            possibleMoveDirection[0] = 1;

        if (dfs_path.back()[0] + possibleMoveDirection[0] * 2 > 0 && dfs_path.back()[0] + possibleMoveDirection[0] * 2 < board.getSize() - 1 && dfs_path.back()[1] + possibleMoveDirection[1] * 2 > 0 && dfs_path.back()[1] + possibleMoveDirection[1] * 2 < board.getSize() - 1)
        {                                                                                                                                  // make sure in between borders of the board
            if (!board.getMaze()[dfs_path.back()[1] + possibleMoveDirection[1] * 2][dfs_path.back()[0] + possibleMoveDirection[0] * 2][1]) // unvisited
            {
                vector<int> possibleMoveRange = {possibleMoveDirection[0], possibleMoveDirection[1]}; // possible move {x,y}
                unvisitedNeighbors.push_back(possibleMoveRange);
            }
        }
    }

    if (unvisitedNeighbors.size() > 0) // all possible moves
    {
        randomNeighbor = rand() % unvisitedNeighbors.size(); // random neighbor index according to it's size
        for (int i = 0; i < !isFirstMove + 1; i++)           // first will run once, then twice for each direction
        {
            vector<int> new_position;

            new_position.push_back(dfs_path.back()[0] + unvisitedNeighbors[randomNeighbor][0]);
            new_position.push_back(dfs_path.back()[1] + unvisitedNeighbors[randomNeighbor][1]);

            dfs_path.push_back(new_position);

            board.setWall(dfs_path.back()[1], dfs_path.back()[0], 0, false);
            board.setWall(dfs_path.back()[1], dfs_path.back()[0], 1, true);
        }
        return true;
    }
    else
        return false;
}
