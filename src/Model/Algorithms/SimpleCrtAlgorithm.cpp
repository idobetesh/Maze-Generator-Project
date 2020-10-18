#include "SimpleCrtAlgorithm.h"

void SimpleCrtAlgorithm::runAlgorithm(Maze2d &board)
{
    this->generateMaze(board);
}

void SimpleCrtAlgorithm::generateMaze(Maze2d &board)
{
    int mazeSize = board.getSize();
    int startPitRow = rand() % 3 + 1;
    int endPitRow = rand() % 2 + mazeSize - 4;

    vector<int> startP = {startPitRow, 0};
    vector<int> endP = {endPitRow, mazeSize - 1};

    board.setWall(startPitRow, 0, 0, 0);          // set maze entrance position
    board.setWall(endPitRow, mazeSize - 1, 0, 0); // set maze exit position

    Position startPos(startPitRow, 0);
    Position endPos(endPitRow, mazeSize - 1);
    board.setStartPosition(startPos);
    board.setGoalPosition(endPos);

    vector<int> curr_pos = {startPitRow, 0};                 // entrance
    vector<vector<int>> path = {curr_pos, {startPitRow, 1}}; // path >> entrance and one step right inside the maze
    curr_pos = path[1];                                      //set curr_pos to it's new position

    // cout << "start {" << path[0][0] << ", 0}\n end {" << endPitRow << ", " << mazeSize - 1 << "}\n"
    //      << "current {" << path[1][0] << ", " << path[1][1] << "}\n========" << endl;

    bool success = false;
    while (!success)
    {
        if (curr_pos[0] == endP[0] && curr_pos[1] == endP[1])
            success = true;

        if (curr_pos[0] == endP[0])
        {
            while (curr_pos[1] != endP[1]) // once you hit the endPitRow go right until you got exit
            {
                vector<int> path_step = {curr_pos[0], curr_pos[1] + 1};
                if (curr_pos[1] < endP[1])
                {
                    curr_pos[1] += 1;
                    path.push_back(path_step);
                }

                // cout << "GOAL RIGHT! {" << path_step[0] << ", " << path_step[1] << "}" << endl;
                if (curr_pos[1] == endP[1] && curr_pos[1] == endP[1])
                {
                    success = true;
                    // cout << "SUCCESS!" << endl;
                    break;
                }
            }
        }

        if (curr_pos[1] == endP[1] - 1)
        {
            while (curr_pos[0] != endP[0]) // once you hit the endPitCol go down until you got exit row
            {
                vector<int> path_step = {curr_pos[0] + 1, curr_pos[1]};
                if (curr_pos[0] < endP[0])
                {
                    curr_pos[0] += 1;
                    path.push_back(path_step);
                }

                // cout << "GOAL DOWN! {" << path_step[0] << ", " << path_step[1] << "}" << endl;
                if (curr_pos[0] == endP[0] && curr_pos[1] == endP[1])
                {
                    success = true;
                    // cout << "SUCCESS! 1" << endl;
                    curr_pos[1] += 1;
                    path.push_back(path_step);
                    break;
                }
            }
        }

        int tmp = rand() % 2; // 0-1

        if (curr_pos[0] == endP[0] && curr_pos[1] == endP[1])
            break;

        if (curr_pos[1] < mazeSize && curr_pos[0] < endP[0] && tmp == S_DOWN)
        {
            vector<int> path_step = {curr_pos[0] + 1, curr_pos[1]};
            curr_pos[0] += 1;
            path.push_back(path_step);
            // cout << "DOWN {" << path_step[0] << ", " << path_step[1] << "}" << endl;
        }

        if (curr_pos[1] == endP[1])
            break;

        if (curr_pos[1] < endP[1] && tmp == S_RIGHT)
        {
            vector<int> path_step = {curr_pos[0], curr_pos[1] + 1};
            curr_pos[1] += 1;
            path.push_back(path_step);
            // cout << "RIGHT {" << path_step[0] << ", " << path_step[1] << "}" << endl;
        }

        if (curr_pos[0] == endP[0] && curr_pos[1] == endP[1])
            success = true;
    }

    path.pop_back(); // will pop off the end and so the exit remains clear!

    int path_size = path.size();
    for (int k = 0; k < path_size; k++)
        board.setWall(path[k][0], path[k][1], 0, 1);

    int RowOrColNew = 0;
    int RowOrColOld = 0, Coltmp = 2, Rowtmp = 2;

    for (int i = 2; i < mazeSize - 2; i++)
    {
        RowOrColNew = rand() % 2; // 0 for row 1 for col
        if (RowOrColNew == RowOrColOld)
        {
            if (RowOrColNew == 1)
                RowOrColNew = 0;
            if (RowOrColNew == 0)
                RowOrColNew = 1;
        }
        if (RowOrColNew == 0)
        { // if row
            int tmpRow1 = Rowtmp, tmpCol1 = 1;
            for (int j = 1; j < mazeSize - 1; j++)
            {
                if (board.getMaze()[tmpRow1][tmpCol1][0] != true)
                { // if there is no wall in this spot
                    int rnd = rand() % 2;
                    board.setWall(tmpRow1, tmpCol1, 0, rnd);
                }
                tmpCol1 += 1;
            }
            Coltmp++;
            Rowtmp++;
        }
        if (RowOrColNew == 1)
        { // if col
            int tmpRow1 = 1, tmpCol1 = Rowtmp;
            for (int j = 1; j < mazeSize - 1; j++)
            {
                if (board.getMaze()[tmpRow1][tmpCol1][0] != true)
                { // if there is no wall in this spot
                    int rnd = rand() % 2;
                    board.setWall(tmpRow1, tmpCol1, 0, rnd);
                }
                tmpRow1 += 1;
            }
            Coltmp++;
            Rowtmp++;
        }
        RowOrColOld = RowOrColNew;
    }

    for (int k = 0; k < path_size; k++)
        board.setWall(path[k][0], path[k][1], 0, 0);
}