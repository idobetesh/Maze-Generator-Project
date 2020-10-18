#pragma once
#include "Model.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

class Command
{
public:
    virtual void execute(vector<string> parsedInput, Model *_m) = 0;
};