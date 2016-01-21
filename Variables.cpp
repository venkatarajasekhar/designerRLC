#include "Variables.h"

// Destructor of object and free memory
Variable::~Variable() {
    if (this->name != nullptr) {
        free(this->name);
        this->name = nullptr;
    }
}

Variable::Variable() {

}

Variable::Variable(const Variable & a) {
    int length;
    value = a.value;
    length = (int) std::strlen(a.name);
    name = (char *) malloc(sizeof(char) * length);
    std::strcpy(name, a.name);
}

Variable & Variable::operator=(const Variable & a) {
    int length;
    value = a.value;
    length = (int) std::strlen(a.name);
    name = (char *) malloc(sizeof(char) * length);
    std::strcpy(name, a.name);
    return *this;
}

int loadVariables(char *pathSource, std::vector<Variable> &globVariable) {
    std::ifstream ifs(pathSource); // nacteni souboru
    char newLine[50];
    int lineLength = 0, i = 0;
    struct Variable tmpVariable;
    while (ifs.getline(newLine, 50)) {
        lineLength = (int) std::strlen(newLine);
        for (i = 0; i < lineLength; i++) {
            if (newLine[i] == '=') {
                copyNameOfVariable(tmpVariable, i, newLine);
                readValueFromString(tmpVariable, newLine + i + 1);
                globVariable.push_back(tmpVariable);
                free(tmpVariable.name);
                tmpVariable.name = nullptr;
                break;
            }
        }
    }
}

void copyNameOfVariable(struct Variable &tmpVariable, int size, const char *name) {
    int i;
    tmpVariable.name = (char *) malloc(sizeof(char) * size);
    for (i = 0; i < size - 1; i++) {
        tmpVariable.name[i] = name[i];
    }
    tmpVariable.name[size - 1] = '\0';
}


void readValueFromString(struct Variable &tmpVariable, const char *source) {
    std::sscanf(source, "%lf", &tmpVariable.value);
}


void printGlobalVariable(std::vector<Variable> &globVariable) {
    int i = 0;
    for (i = 0; i < globVariable.size(); i++) {
        std::cout << globVariable[i].name << " " << globVariable[i].value << "\n";
    }
}

int searchVariableInVariablesStore(std::vector<Variable> & vectorStore, const char * findVariableName) {
    int i, count = (int) vectorStore.size();
    for (i = 0; i < count; i++) {
        if (std::strcmp(vectorStore[i].name, findVariableName) == 0) {
            return i;
        }
    }
    return -1;
}