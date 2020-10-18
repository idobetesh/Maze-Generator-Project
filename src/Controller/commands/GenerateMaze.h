#pragma once
#include "Command.h"

class GenerateMaze : public Command
{
public:
    virtual void execute(vector<string> parsedInput, Model *_m)
    {
        // parsedInput[0] + parsedInput[1] = "generate maze"
        // parsedInput[2] = <name>
        // parsedInput[3] = <(int)size>

        int size = 0;
        for (int i = 0; i < parsedInput[3].length(); i++) // convert the string to int
        {
            size = size * 10 + parsedInput[3][i] - '0';
        }

        /* check if valid */
        if (size < 5)
            size = 5;
        if (size % 2 == 0)
            size++;

        _m->generate(parsedInput[2], size);
    }
};