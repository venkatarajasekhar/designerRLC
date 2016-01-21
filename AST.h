#ifndef DESIGNERRLC_AST_H
#define DESIGNERRLC_AST_H

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>

enum OPERATION{
    NONE, PLUS, MINUS, DIVIDE, MULTIPLE, SQRT
};

struct AST {
    struct AST * node_l = nullptr, * node_r = nullptr;
    int OPERATOR;
    double value_l = 0, value_r = 0;
};

void deleteAST(struct AST *root);
struct AST * createNode(struct AST * node, int operation, double value);
int isDigit(const char c);
int isFunction(const char c);
void parseExpression(const char * expression);
#endif //DESIGNERRLC_AST_H
