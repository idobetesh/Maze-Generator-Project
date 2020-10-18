#include "Maze2dGenerator.h"

string Maze2dGenerator::measureAlgorithmTime(int size)
{
    clock_t begin, end;
    double time_spent;
    begin = clock();
    this->generate("try", size);
    end = clock();
    time_spent = (double)(end-begin);
    string times = to_string(time_spent);
    times += " clocks per second";
    return times;
}