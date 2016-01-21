#include "AST.h"

struct AST *createNode(struct AST *node, int operation, double value) {
    node->node_r = (struct AST *) malloc(sizeof(struct AST));
    node->node_r->OPERATOR = operation;
    node->value_l = value;
    return node->node_r;
}

void deleteAST(struct AST *root) {
    if (root->node_r != nullptr) {
        deleteAST(root->node_r);
    }
    if (root->node_l != nullptr) {
        deleteAST(root->node_l);
    }
    free(root);
}

void parseExpression(const char * expression) {
    struct AST root;
    struct AST * current;
    current = &root;
    int stringLength = (int) std::strlen(expression), i = 0, state = 0;
    double tmpValue = 0;
    std::string ss = "";

    for(i = 0; i < stringLength;i++) {
        if (isDigit(expression[i])){
            tmpValue *= 10;
            tmpValue += expression[i] - '0';
            state = 1;
        } else if (expression[i] == ')' || expression[i] == '(') {
            continue;
        } else {
            if (!isFunction(expression[i])) {
                ss += expression[i];
            } else {
                if (!state) {

                } else {

                }
            }
        }
    }
}
int isDigitDot(const char c) {
    if (c == 0) return 0;
    return std::strchr("0123456789.", c) != 0;
}

int isDigit(const char c) {
    if (c == 0) return 0;
    return std::strchr("0123456789", c) != 0;
}

int isFunction(const char c) {
    return std::strchr("*/-+", c) != 0;
}