#pragma once
#include "Command.h"

class Display : public Command
{
public:
    virtual void execute(vector<string> parsedInput, Model *_m)
    {
        // parsedInput[0] = "display"
        // parsedInput[1] = <name>

        _m->display(parsedInput[1]);
    }
};