#pragma once
#include "Command.h"

class FileSize : public Command
{
public:
    virtual void execute(vector<string> parsedInput, Model *_m)
    {
        // parsedInput[0] + parsedInput[1] = "file size"
        // parsedInput[2] = <name>

        string cmd = "dir ";
        cmd += parsedInput[2];
        
        cout << cmd << endl;
        system(cmd.c_str());
    }
};