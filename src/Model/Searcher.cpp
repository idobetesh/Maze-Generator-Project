#include "Searcher.h"

int Searcher::getNumberOfNodesEvaluated() { return m_evaluatedNodes; }
const Position &Searcher::popOpenList()
{
    m_evaluatedNodes++;
    return m_openList.top();
}