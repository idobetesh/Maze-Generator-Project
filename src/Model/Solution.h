#pragma once
#include <vector>
#include "Position.h"
#include <memory>

class Solution
{
private:
	vector<Position *> m_solution;

public:
	Solution() = default;
	Solution(const Solution &other)
	{
		for (int i = 0; i < other.m_solution.size(); i++)
			m_solution.push_back(other.m_solution[i]);
	}
	void pushToSolution(Position *posPtr) { m_solution.push_back(posPtr); }
	vector<Position *> &getSolutionVec() { return m_solution; }
	~Solution()
	{
		for (auto &pos : m_solution)
			delete pos;
	};
};
