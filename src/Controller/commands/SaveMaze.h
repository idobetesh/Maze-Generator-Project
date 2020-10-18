#pragma once
#include "Command.h"

class SaveMaze : public Command
{
public:
    virtual void execute(vector<string> parsedInput, Model *_m)
    {
        // parsedInput[0] + parsedInput[1] = "save maze"
        // parsedInput[2] = <name>
        // parsedInput[3] = <file name>

        _m->save(parsedInput[2], parsedInput[3]);
    }
};