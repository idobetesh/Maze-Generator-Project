#pragma once
#include "Command.h"

class LoadMaze : public Command
{
public:
    virtual void execute(vector<string> parsedInput, Model *_m)
    {
        // parsedInput[0] + parsedInput[1] = "load maze"
        // parsedInput[2] = <file name>
        // parsedInput[3] = <name>

        _m->load(parsedInput[2], parsedInput[3]);
    }
};