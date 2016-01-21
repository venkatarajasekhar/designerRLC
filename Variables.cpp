#include "Variables.h"

void loadVariables(const char *pathSource, std::vector<Variable> &globVariable) {
    std::ifstream ifs(pathSource); // nacteni souboru
    std::string newLine;
    int lineLength = 0, i = 0;
    struct Variable tmpVariable;
    while (getline(ifs, newLine)) {
        std::stringstream ss(newLine);
        char equal;
        ss >> tmpVariable.name >> equal >> tmpVariable.value;
        globVariable.push_back(tmpVariable);
    }
}

void printGlobalVariable(std::vector<Variable> &globVariable) {
    int i = 0;
    for (i = 0; i < globVariable.size(); i++) {
        std::cout << globVariable[i].name << " " << globVariable[i].value << "\n";
    }
}

void pushVariableToGlobVariables(std::vector<Variable> &globVariables, std::string name, double value) {
    struct Variable tmp;
    tmp.value = value;
    tmp.name = name;
    globVariables.push_back(tmp);
}

void initMathVariable(std::vector<Variable> &globVariables) {
    pushVariableToGlobVariables(globVariables, "PI", 3.1415);
    pushVariableToGlobVariables(globVariables, "E", 2.1);
}

int searchVariableInVariablesStore(std::vector<Variable> &vectorStore, std::string findVariableName) {
    int i, count = (int) vectorStore.size();
    for (i = 0; i < count; i++) {
        if (vectorStore[i].name.compare(findVariableName) == 0) {
            return i;
        }
    }
    return -1;
}