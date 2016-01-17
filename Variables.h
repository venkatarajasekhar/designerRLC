#ifndef DESIGNERRLC_VARIABLES_H
#define DESIGNERRLC_VARIABLES_H

#include <vector>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <iostream>

struct Variable{
    char *name = nullptr;
    double value;
};

int loadVariables(char * pathSource, std::vector<Variable> & globVariable);
void printGlobalVariable(std::vector<Variable> &globVariable);
void copyNameOfVariable(struct Variable & tmpVariable, int size, const char * name);
void readValueFromString(struct Variable &tmpVariable, const char *source);
int searchVariableInVariablesStore(std::vector<Variable> & vectorStore, const char * findVariableName);

#endif //DESIGNERRLC_VARIABLES_H
