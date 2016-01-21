#ifndef DESIGNERRLC_VARIABLES_H
#define DESIGNERRLC_VARIABLES_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

struct Variable {
    std::string name;
    double value;
};

void loadVariables(const char *pathSource, std::vector<Variable> &globVariable);

void printGlobalVariable(std::vector<Variable> &globVariable);

int searchVariableInVariablesStore(std::vector<Variable> &vectorStore, std::string findVariableName);


void initMathVariable(std::vector<Variable> &globVariables);


#endif //DESIGNERRLC_VARIABLES_H
