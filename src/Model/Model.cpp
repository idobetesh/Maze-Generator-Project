#include "Model.h"

Model::~Model()
{
    for (auto it = _cache.begin(); it != _cache.end(); it++)
    {
        delete it->second.first;
        delete it->second.second;
    }
}
void Model::generate(string name, int size)
{
    MyMaze2dGenerator my;
    auto mz = my.generate(name, size);
    Maze2d *maze = new Maze2d(mz);
    _cache[name] = {maze, nullptr};
}

void Model::solve(string name, string algoName)
{
    auto it = _cache.find(name);
    if (it != _cache.end())
    {
        Maze2d *tmpMaze = it->second.first;
        Adapter ad(*tmpMaze);
        HeuristicFunc *h_air = new AirDistanceHeuristic();
        Solution *sol = new Solution();

        if (algoName.compare("A*") == 0)
        {
            AStarAlgorithm *A = new AStarAlgorithm(h_air);
            Solution *solution = new Solution(ad.solve2dMaze(A));
            _cache[name].second = solution;
        }
        else if (algoName.compare("BFS") == 0)
        {
            BFSAlgorithm *bfs = new BFSAlgorithm(h_air);
            Solution *solution = new Solution(ad.solve2dMaze(bfs));
            _cache[name].second = solution;
        }
        else
            throw new WrongAlgorithmName();
    }
    else
        throw new WrongMazeName();
}

void Model::save(string name, string fileName)
{
    auto it = _cache.find(name);
    if (it != _cache.end())
    {
        MazeComperssion mazeComp(*(it->second.first));
        fileName += ".bin";

        ofstream outFile;
        outFile.open(fileName, ios::binary | ios::out);
        mazeComp.save(outFile);
        outFile.close();
    }
    else
        throw new WrongMazeName();
}

void Model::load(string fileName, string name)
{
    MazeComperssion mazeComp;
    fileName += ".bin";
    ifstream InFile;
    InFile.open(fileName, ios::binary | ios::in);
    Maze2d *lodedMaze = new Maze2d(mazeComp.load(InFile));
    InFile.close();
    if (lodedMaze)
        _cache[name] = {lodedMaze, nullptr};
}

void Model::display(string name)
{
    auto it = _cache.find(name);
    if (it != _cache.end())
    {
        cout << "Maze2d '" << name << "' " << endl;
        cout << *(it->second.first) << endl;
    }
    else
        throw new WrongMazeName();
}

void Model::displaySolution(string name)
{
    auto it = _cache.find(name);
    if (it != _cache.end())
    {
        if (it->second.second == nullptr)
        {
            cout << "Sorry, no solution for this maze yet" << endl;
            return;
        }
        Solution sol = *(it->second.second);
        Maze2d mz = *(it->second.first);

        int row = 0;
        int col = 0;
        for (int i = 0; i < sol.getSolutionVec().size(); i++)
        {
            row = sol.getSolutionVec()[i]->getRow();
            col = sol.getSolutionVec()[i]->getCol();
            mz.setWall(row, col, 1, 1);
        }
        cout << "Maze2d '" << name << "' solution:" << endl;
        cout << mz << endl;
    }
    else
        throw new WrongMazeName();
}

void Model::getMazeSize(string name)
{
    auto it = _cache.find(name);
    if (it != _cache.end())
    {
        int mazeSize = sizeof(*(it->second.first));
        cout << "size of Maze2d '" << name << "' is " << mazeSize << " bytes" << endl;
    }
    else
        throw new WrongMazeName();
}