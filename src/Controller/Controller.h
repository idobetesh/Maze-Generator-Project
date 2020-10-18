#pragma once
#include "Model.h"
#include "Command.h"
#include "Dir.h"
#include "GenerateMaze.h"
#include "Display.h"
#include "SaveMaze.h"
#include "LoadMaze.h"
#include "MazeSize.h"
#include "FileSize.h"
#include "Solve.h"
#include "DisplaySolution.h"

class Controller
{
private:
    Model *_model;
    Command *_command;

public:
    Controller()
    {
        _model = new Model();
    }
    void doCommand(Command *c, vector<string> parsedInput)
    {
        _command = c;
        _command->execute(parsedInput, _model);
    }
    ~Controller()
    {
        delete _model;
        delete _command;
    };
};