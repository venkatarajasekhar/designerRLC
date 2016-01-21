#ifndef DESIGNERRLC_EXPRESSION_H
#define DESIGNERRLC_EXPRESSION_H

#include <vector>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <iostream>

struct Expression{
    char * name = nullptr;
    char * expression = nullptr;
    ~Expression();
    Expression();
    Expression(const Expression & a);
};

void loadExpressions(char *pathSource, std::vector<Expression> &globExpression);
void copyNameOfExpression(struct Expression &tmpExpression, int size, const char *name);
void copyExpressionToExpression(struct Expression &tmpExpression, int size, int position, const char *name);
void printGlobalExpressions(std::vector<Expression> &globalExpression);

#endif //DESIGNERRLC_EXPRESSION_H
