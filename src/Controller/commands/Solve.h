#pragma once
#include "Command.h"

class Solve : public Command
{
public:
    virtual void execute(vector<string> parsedInput, Model *_m)
    {
        // parsedInput[0] = "solve"
        // parsedInput[1] = <name>
        // parsedInput[2] = <algorithm>

        _m->solve(parsedInput[1], parsedInput[2]);
    }
};