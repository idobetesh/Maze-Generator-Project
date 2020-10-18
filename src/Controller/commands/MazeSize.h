#pragma once
#include "Command.h"

class MazeSize : public Command
{
public:
    virtual void execute(vector<string> parsedInput, Model *_m)
    {
        // parsedInput[0] + parsedInput[1] = "maze size"
        // parsedInput[2] = <name>

        _m->getMazeSize(parsedInput[2]);
    }
};