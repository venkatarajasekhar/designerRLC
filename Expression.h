#ifndef DESIGNERRLC_EXPRESSION_H
#define DESIGNERRLC_EXPRESSION_H

#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

struct Expression{
    std::string name;
    std::string expression;
};

void loadExpressions(char *pathSource, std::vector<Expression> &globExpression);
void printGlobalExpressions(std::vector<Expression> &globalExpression);

#endif //DESIGNERRLC_EXPRESSION_H
