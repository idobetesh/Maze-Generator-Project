

// #include "AStarAlgorithm.h"
// #define STEP 10
// Solution AStarAlgorithm::search(Searchable &s)
// {
//     Solution solution;
//     Position curr_pos;
//     vector<Position> currentPossibleMoves;

//     curr_pos = s.getStartPosition();
//     m_openList.push(curr_pos);

//     Position *tmpPos = new Position(curr_pos);
//     solution.pushToSolution(tmpPos); //push start position to sulotion vector

//     bool success = false;
//     while (!success || !m_openList.empty())
//     {
//         if (curr_pos == s.getGoalPosition())
//         {
//             success = true;
//             while (1)
//             {
//                 if (curr_pos == s.getStartPosition())
//                     return solution;

//                 curr_pos = *(curr_pos.getCameFromPosition());
//                 Position *tmpPosi = new Position(curr_pos);
//                 solution.pushToSolution(tmpPosi);

//                 //cout << "hi" << endl;
//             }
//             break;
//         }
//         curr_pos = popOpenList(); //m_openList.top();
//         currentPossibleMoves = s.getPossibleOptions(curr_pos);
//         m_openList.pop();
//         curr_pos.setgCost(curr_pos.getgCost() + STEP);

//         for (auto &po : currentPossibleMoves)
//         {

//             Fcalculator(po, s.heuristicManhattanDistance(po));

//             if (s.getMazeFromSearchable().getMaze()[po.getRow()][po.getCol()][1] == false)
//             {
//                 Position *tmpPos = new Position(curr_pos);
//                 po.setCameFromPosition(*tmpPos);
//                 m_openList.push(po);
//             }
//         }

//         s.getMazeFromSearchable().setWall(curr_pos.getRow(), curr_pos.getCol(), 1, 1); // set to visited

//         if ((s.getGoalPosition().getRow() == curr_pos.getRow() - 1 && s.getGoalPosition().getCol() == curr_pos.getCol()) ||
//             (s.getGoalPosition().getRow() == curr_pos.getRow() + 1 && s.getGoalPosition().getCol() == curr_pos.getCol()) ||
//             (s.getGoalPosition().getRow() == curr_pos.getRow() && s.getGoalPosition().getCol() == curr_pos.getCol() - 1) ||
//             (s.getGoalPosition().getRow() == curr_pos.getRow() && s.getGoalPosition().getCol() == curr_pos.getCol() + 1))
//         {
//             m_openList.push(s.getGoalPosition());
//             curr_pos = s.getGoalPosition();
//             s.getMazeFromSearchable().setWall(s.getGoalPosition().getRow(), s.getGoalPosition().getCol(), 1, 1);
//         }

//         for (int i = 0; i < currentPossibleMoves.size(); i++)
//         {
//             int rows = currentPossibleMoves[i].getRow();
//             int cols = currentPossibleMoves[i].getCol();

//             if (s.getMazeFromSearchable().getMaze()[rows][cols][1] == true || rows < s.getMazeFromSearchable().getSize() + 1 || cols < s.getMazeFromSearchable().getSize() + 1 || rows > -1 || cols > -1)
//             {
//                 currentPossibleMoves.erase(currentPossibleMoves.begin() + i);
//             }
//         }
//         if (currentPossibleMoves.size() == 0)
//         {
//             continue;
//         }
//     }
//     return solution;
// };

// void AStarAlgorithm::Fcalculator(Position &pos, int hFromPosition)
// {
//     double sum = pos.getgCost() + STEP + hFromPosition * STEP;
//     pos.sethCost(sum);
// };

// #include "AStarAlgorithm.h"
// #define STEP 10
// Solution AStarAlgorithm::search(Searchable &s)
// {
//     Solution solution;
//     Position curr_pos;
//     vector<Position> currentPossibleMoves;

//     curr_pos = s.getStartPosition();
//     m_openList.push(curr_pos);

//     bool success = false;
//     while (!success || !m_openList.empty())
//     {
//         curr_pos = popOpenList(); //m_openList.top();
//         Position *tmppos = new Position(popOpenList());
//         cout << *(tmppos) << "yoyoyoy" << endl;
//         currentPossibleMoves = s.getPossibleOptions(curr_pos);
//         m_openList.pop();
//         //Position* tmpPos = new Position(curr_pos);
//         //solution.pushToSolution(tmpPos);
//         curr_pos.setgCost((curr_pos.getgCost() + STEP));

//         for (auto &po : currentPossibleMoves)
//         {
//             Fcalculator(po, _heu->calculateHeuristic(po, s.getMazeFromSearchable()));

//             if (s.getMazeFromSearchable().getMaze()[po.getRow()][po.getCol()][1] == false)
//             {
//                 po.setCameFromPosition(tmppos); // push the pointer to the to the came from field
//                 m_openList.push(po);
//             }
//         }

//         s.getMazeFromSearchable().setWall(curr_pos.getRow(), curr_pos.getCol(), 1, 1); // set to visited
//         Position *posPtr = nullptr;
//         posPtr = &curr_pos;

//         if ((s.getGoalPosition().getRow() == curr_pos.getRow() - 1 && s.getGoalPosition().getCol() == curr_pos.getCol()) ||
//             (s.getGoalPosition().getRow() == curr_pos.getRow() + 1 && s.getGoalPosition().getCol() == curr_pos.getCol()) ||
//             (s.getGoalPosition().getRow() == curr_pos.getRow() && s.getGoalPosition().getCol() == curr_pos.getCol() - 1) ||
//             (s.getGoalPosition().getRow() == curr_pos.getRow() && s.getGoalPosition().getCol() == curr_pos.getCol() + 1))
//         {
//             m_openList.push(s.getGoalPosition());
//             success = true;
//             curr_pos = s.getGoalPosition();

//             s.getMazeFromSearchable().setWall(s.getGoalPosition().getRow(), s.getGoalPosition().getCol(), 1, 1);
//             //solution.pushToSolution(&(s.getGoalPosition()));
//             while (1)
//             {
//                 if (curr_pos == s.getStartPosition())
//                 {
//                     //break;
//                     return solution;
//                 }
//                 curr_pos = *(curr_pos.getCameFromPosition());
//                 cout << "the order of solution is - " << *(curr_pos.getCameFromPosition()) << endl;
//                 solution.pushToSolution(curr_pos.getCameFromPosition());
//             }
//             // for (int i = 0; i < s.getMazeFromSearchable().getSize(); i++)
//             // {
//             //     for (int j = 0; j < s.getMazeFromSearchable().getSize(); j++)
//             //     {
//             //         if (s.getMazeFromSearchable().getMaze()[i][j][1])
//             //         {
//             //             bool flag = false;
//             //             for (auto &sol : solution.getSolutionVec())
//             //             {
//             //                 if (i == sol->getRow() && j == sol->getCol()){
//             //                     break;
//             //                 }
//             //                 if (sol == *solution.getSolutionVec().end())
//             //                     flag = true;
//             //             }
//             //             if (flag == true)
//             //                 s.getMazeFromSearchable().setWall(i, j, 1, 0);
//             //         }
//             //     }
//             // }
//             // return solution;
//             // //solution.pushToSolution(&s.getGoalPosition());
//             // break;
//         }

//         for (int i = 0; i < currentPossibleMoves.size(); i++)
//         {
//             int rows = currentPossibleMoves[i].getRow();
//             int cols = currentPossibleMoves[i].getCol();

//             if (s.getMazeFromSearchable().getMaze()[rows][cols][1] == true || rows < s.getMazeFromSearchable().getSize() + 1 || cols < s.getMazeFromSearchable().getSize() + 1 || rows > -1 || cols > -1)
//             {
//                 currentPossibleMoves.erase(currentPossibleMoves.begin() + i);
//             }
//         }

//         if (currentPossibleMoves.size() == 0)
//         {
//             continue;
//         }
//     }
//     return solution;
// };






// ========================================================================================================

#include "AStarAlgorithm.h"
#define STEP 10
Solution AStarAlgorithm::search(Searchable &s)
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
            Fcalculator(po, _heu->calculateHeuristic(po, s.getMazeFromSearchable()));

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
            Position *tmpPos = new Position(s.getGoalPosition());
            solution.pushToSolution(tmpPos);
            //solution.pushToSolution(&s.getGoalPosition());
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


void AStarAlgorithm::Fcalculator(Position &pos, int hFromPosition)
{
    double sum = pos.getgCost() + STEP + hFromPosition * STEP;
    pos.sethCost(sum);
};

// ========================================================================================================





//try

// #include "AStarAlgorithm.h"
// #define STEP 10

// Solution AStarAlgorithm::search(Searchable &s)
// {
//     Solution solution;
//     Position curr_pos;
//     vector<Position> currentPossibleMoves;

//     curr_pos = s.getStartPosition();
//     Position endPos = s.getGoalPosition();
//     Position* almostEndPos;
//     cout << "you are at line 298" << endl;
//     if( endPos.getRow() - 1 > 0){
//         if(s.getMazeFromSearchable().getMaze()[endPos.getRow() - 1][endPos.getCol()][0] != true ){
//             cout <<"YONIGGAdddddd!\n";
//             almostEndPos = new Position(endPos.getRow() - 1, endPos.getCol());
//             cout << "HERE1"<< endl;
//         }
//     }    
//     if( endPos.getRow() + 1 < s.getMazeFromSearchable().getSize()- 1){
//         if(s.getMazeFromSearchable().getMaze()[endPos.getRow() + 1][endPos.getCol()][0] != true){
//             cout <<"YONIGGAdddddd1!\n";
//             almostEndPos = new Position(endPos.getRow() + 1, endPos.getCol());
//             cout << "HERE2"<< endl;
//         }
        
//     }
//     if( endPos.getCol() - 1 > 0){
//         if(s.getMazeFromSearchable().getMaze()[endPos.getRow()][endPos.getCol() - 1][0] != true){
//             cout <<"YONIGGAdddddd2!\n";
//             almostEndPos = new Position(endPos.getRow(), endPos.getCol() - 1);
//             cout << "HERE3"<< endl;
//         }
//     }
//     if(endPos.getCol() + 1 < s.getMazeFromSearchable().getSize() -1){
//         if(s.getMazeFromSearchable().getMaze()[endPos.getRow()][endPos.getCol() + 1][0] != true){
//             cout <<"YONIGGAdddddd3!\n";
//             almostEndPos = new Position(endPos.getRow(), endPos.getCol() + 1);
//             cout << "HERE4"<< endl;
//         }
//     }
//     cout << "you are at line 315" << endl;
//     m_openList.push(curr_pos);

//     solution.pushToSolution(&s.getStartPosition());

//     vector<Position> sol;
//     bool success = false;
//     cout << "you are at line 311" <<endl;
//     while (!success || !m_openList.empty())
//     {
//         if (curr_pos == *almostEndPos)
//         {
//             while (1)
//             {
//                 if (*curr_pos.getCameFromPosition() == s.getStartPosition())
//                     break;

//                 cout << "you are at line 311" << endl;
//                 Position *tmp = new Position(*(curr_pos.getCameFromPosition()));
//                 sol.push_back(*tmp);
//                 solution.pushToSolution(curr_pos.getCameFromPosition());
//                 curr_pos = *curr_pos.getCameFromPosition();
//             }
//             solution.pushToSolution()
//             return solution;
//         }

//         curr_pos = popOpenList(); //m_openList.top();
//         currentPossibleMoves = s.getPossibleOptions(curr_pos);
//         m_openList.pop();

//         Position *tmpPos = new Position(curr_pos);
//         // solution.pushToSolution(tmpPos);

//         for (auto &po : currentPossibleMoves)
//         {
//             Fcalculator(po, _heu->calculateHeuristic(po, s.getMazeFromSearchable()));

//             if (s.getMazeFromSearchable().getMaze()[po.getRow()][po.getCol()][1] == false)
//             {
//                 po.setCameFromPosition(tmpPos);
//                 m_openList.push(po);
//             }
//         }

//         s.getMazeFromSearchable().setWall(curr_pos.getRow(), curr_pos.getCol(), 1, 1); // set to visited

//         if ((s.getGoalPosition().getRow() == curr_pos.getRow() - 1 && s.getGoalPosition().getCol() == curr_pos.getCol()) ||
//             (s.getGoalPosition().getRow() == curr_pos.getRow() + 1 && s.getGoalPosition().getCol() == curr_pos.getCol()) ||
//             (s.getGoalPosition().getRow() == curr_pos.getRow() && s.getGoalPosition().getCol() == curr_pos.getCol() - 1) ||
//             (s.getGoalPosition().getRow() == curr_pos.getRow() && s.getGoalPosition().getCol() == curr_pos.getCol() + 1))
//         {
//             cout << "you are at line 354" <<endl;
//             // m_openList.push(s.getGoalPosition());
//             //curr_pos = s.getGoalPosition();
//             // success = true;
//             s.getMazeFromSearchable().setWall(s.getGoalPosition().getRow(), s.getGoalPosition().getCol(), 1, 1);
//             // solution.pushToSolution(&s.getGoalPosition());
//             // break;
//         }

//         for (int i = 0; i < currentPossibleMoves.size(); i++)
//         {
//             int rows = currentPossibleMoves[i].getRow();
//             int cols = currentPossibleMoves[i].getCol();

//             if (s.getMazeFromSearchable().getMaze()[rows][cols][1] == true || rows < s.getMazeFromSearchable().getSize() + 1 || cols < s.getMazeFromSearchable().getSize() + 1 || rows > -1 || cols > -1)
//             {
//                 currentPossibleMoves.erase(currentPossibleMoves.begin() + i);
//             }
//         }

//         if (currentPossibleMoves.size() == 0)
//         {
//             continue;
//         }
//     }
//     return solution;
// };

// void AStarAlgorithm::Fcalculator(Position &pos, int hFromPosition)
// {
//     int sum = pos.getgCost() + STEP + hFromPosition * STEP;
//     pos.sethCost(sum);
// };