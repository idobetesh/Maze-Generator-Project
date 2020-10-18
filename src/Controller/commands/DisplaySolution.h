#pragma once
#include "Command.h"

class DisplaySolution : public Command
{
public:
    virtual void execute(vector<string> parsedInput, Model *_m)
    {
        // parsedInput[0] + parsedInput[1] = "display solution"
        // parsedInput[2] = <name>

        _m->displaySolution(parsedInput[2]);
    }
};