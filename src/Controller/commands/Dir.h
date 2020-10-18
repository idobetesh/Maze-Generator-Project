#pragma once
#include "dirent.h"
#include "Command.h"

class Dir : public Command
{
public:
    virtual void execute(vector<string> parsedInput, Model *_m)
    {
        // parsedInput[0] = "dir"
        // parsedInput[1] = <path>

        DIR *_dir;
        struct dirent *dire;
        struct stat sta;

        _dir = opendir(parsedInput[1].c_str());
        if (!_dir)
        {
            cout << "Not found" << endl;
        }
        while ((dire = readdir(_dir)) != NULL)
        {
            if (dire->d_name[0] != '.')
            {
                string path = string(parsedInput[1]) + "/" + string(dire->d_name);
                cout << path << endl;
            }
        }
        closedir(_dir);
    }
};