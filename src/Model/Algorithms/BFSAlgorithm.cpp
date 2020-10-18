#include "BFSAlgorithm.h"

Solution BFSAlgorithm::search(Searchable &s)

{
    Solution solution;
    Position curr_pos;
    vector<Position> currentPossibleMoves;

    curr_pos = s.getStartPosition();
    m_openList.push(curr_pos);

    bool success = false;
    while (!success || !m_openList.empty())
    {
        if (curr_pos == s.getGoalPosition())
        {
            success = true;
            break;
        }
        curr_pos = popOpenList(); //m_openList.top();
        currentPossibleMoves = s.getPossibleOptions(curr_pos);
        m_openList.pop();
        Position *tmpPos = new Position(curr_pos);
        solution.pushToSolution(tmpPos);

        for (auto &po : currentPossibleMoves)
        {
            po.sethCost(_heu->calculateHeuristic(po, s.getMazeFromSearchable()));
            if (s.getMazeFromSearchable().getMaze()[po.getRow()][po.getCol()][1] == false)
            {
                m_openList.push(po);
            }
        }

        s.getMazeFromSearchable().setWall(curr_pos.getRow(), curr_pos.getCol(), 1, 1); // set to visited
        Position *posPtr = nullptr;
        posPtr = &curr_pos;

        if ((s.getGoalPosition().getRow() == curr_pos.getRow() - 1 && s.getGoalPosition().getCol() == curr_pos.getCol()) ||
            (s.getGoalPosition().getRow() == curr_pos.getRow() + 1 && s.getGoalPosition().getCol() == curr_pos.getCol()) ||
            (s.getGoalPosition().getRow() == curr_pos.getRow() && s.getGoalPosition().getCol() == curr_pos.getCol() - 1) ||
            (s.getGoalPosition().getRow() == curr_pos.getRow() && s.getGoalPosition().getCol() == curr_pos.getCol() + 1))
        {
            m_openList.push(s.getGoalPosition());
            success = true;
            s.getMazeFromSearchable().setWall(s.getGoalPosition().getRow(), s.getGoalPosition().getCol(), 1, 1);
            solution.pushToSolution(&s.getGoalPosition());
            break;
        }

        for (int i = 0; i < currentPossibleMoves.size(); i++)
        {
            int rows = currentPossibleMoves[i].getRow();
            int cols = currentPossibleMoves[i].getCol();

            if (s.getMazeFromSearchable().getMaze()[rows][cols][1] == true || rows < s.getMazeFromSearchable().getSize() + 1 || cols < s.getMazeFromSearchable().getSize() + 1 || rows > -1 || cols > -1)
            {
                currentPossibleMoves.erase(currentPossibleMoves.begin() + i);
            }
        }

        if (currentPossibleMoves.size() == 0)
        {
            continue;
        }
    }
    return solution;
};