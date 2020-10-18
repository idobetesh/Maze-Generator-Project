#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

class View
{
public:
    View() = default;
    virtual void start() = 0;
    virtual ~View(){};
};