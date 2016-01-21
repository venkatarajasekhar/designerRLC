#include "Expression.h"

void loadExpressions(char *pathSource, std::vector<Expression> &globExpression) {
    std::ifstream ifs(pathSource); // nacteni souboru
    std::string newLine;
    int lineLength = 0, i = 0;
    struct Expression tmpExpression;
    while (getline(ifs, newLine)) {
        char equal;
        std::stringstream ss(newLine);
        ss >> tmpExpression.name >> equal >> tmpExpression.expression;
        globExpression.push_back(tmpExpression);
    }
}

void printGlobalExpressions(std::vector<Expression> &globalExpression) {
    for (int i = 0; i < (int) globalExpression.size(); i++) {
        std::cout << globalExpression[i].name << " " << globalExpression[i].expression << "\n";
    }
}

