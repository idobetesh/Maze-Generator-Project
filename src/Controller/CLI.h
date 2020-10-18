#pragma once
#include <sstream>
#include "View.h"
#include "Controller.h"

class CLI : public View
{
private:
    unordered_map<string, Command *> _commands;
    istream &_in;
    ostream &_out;
    Controller *_controller;

public:
    CLI();
    CLI(std::istream &in, std::ostream &out);
    virtual void start();
    vector<string> decipherCommand(string input);
    void menu();
    virtual ~CLI();
};

CLI::CLI(std::istream &in, std::ostream &out) : _in(in), _out(out)
{
    _commands = { {"dir",              new Dir()            },
                  {"generate maze",    new GenerateMaze()   },
                  {"display",          new Display()        },
                  {"save maze",        new SaveMaze()       },
                  {"load maze",        new LoadMaze()       },
                  {"maze size",        new MazeSize()       },
                  {"file size",        new FileSize()       },
                  {"solve",            new Solve()          },
                  {"display solution", new DisplaySolution()} };
}

CLI::~CLI()
{
    for (auto it = _commands.begin(); it != _commands.end(); it++)
        delete it->second;

    delete _controller;
}

void CLI::menu()
{
    _out << "\n\nWelcome to The Maze2d World\nenter your command according to the instractios below" << endl;
    _out << "1.dir <path>" << endl;
    _out << "2.generate maze <name> <size>" << endl;
    _out << "3.display <name>" << endl;
    _out << "4.save maze <name> <file name no extension needed>" << endl;
    _out << "5.load maze <file name no extension needed> <name>" << endl;
    _out << "6.maze size <name>" << endl;
    _out << "7.file size <file name no extension needed>" << endl;
    _out << "8.solve <name> <algorithm A* / BFS>" << endl;
    _out << "9.display solution <name>" << endl;
    _out << "10.exit" << endl;
}

vector<string> CLI::decipherCommand(string input) // returns the input parsed by spaces
{
    vector<string> cs;
    string buf;             
    stringstream ss(input); 
    while (ss >> buf)
        cs.push_back(buf);

    return cs; //example: save maze <maze1> <maze1.bin> -> _commands[cmd[0] + " " + cmd[1]]
               //example: dir <HomeWork> -> _commands[cmd[0]]
}

void CLI::start()
{
    _controller = new Controller();
    string input;
    // menu();

    while (1)
    {
        _out << "> ";
        getline(_in, input);

        if(input.compare("exit") == 0)
            break;

        if(input.compare("help") == 0)
            menu();

        vector<string> cmd = decipherCommand(input);
        if (cmd.size() > 1)
        {
            string twoWordCmd = cmd[0] + " " + cmd[1]; 
            if (_commands.find(twoWordCmd) == _commands.end())
            {
                if (_commands.find(cmd[0]) == _commands.end())
                    _out << "Sorry, the command '" << input << "' was not found" << endl; 
                else
                     _controller->doCommand(_commands[cmd[0]], cmd); //one word command        
            }
            else
                _controller->doCommand(_commands[twoWordCmd], cmd); //two words command 
        }
        else 
            _out << "Sorry, the command '" << input << "' was not found" << endl;            
    }
    _out << "Goodbye :)" << endl;
    _in.get();
}