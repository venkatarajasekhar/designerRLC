#include "Expression.h"

// Destructor free memory
Expression::~Expression() {
    if (this->name != nullptr) {
        free(this->name);
        this->name = nullptr;
    }

    if (this->expression != nullptr) {
        free(this->expression);
        this->expression = nullptr;
    }
}


Expression::Expression() {

}

Expression::Expression(const Expression & a) {
    int sizeName, sizeExpresion;
    sizeName = (int) std::strlen(a.name);
    name = (char *) malloc(sizeof(char) * sizeName);
    std::strcpy(name, a.name);

    sizeExpresion= (int) std::strlen(a.expression);
    expression = (char *) malloc(sizeof(char) * sizeExpresion);
    std::strcpy(expression, a.expression);
}

void loadExpressions(char *pathSource, std::vector<Expression> &globExpression) {
    std::ifstream ifs(pathSource); // nacteni souboru
    char newLine[50];
    int lineLength = 0, i = 0;
    struct Expression tmpExpression;
    while (ifs.getline(newLine, 50)) {
        lineLength = (int) std::strlen(newLine);
        for (i = 0; i < lineLength; i++) {
            if (newLine[i] == '=') {
                copyNameOfExpression(tmpExpression, i, newLine);
                copyExpressionToExpression(tmpExpression, lineLength - i - 1, i + 2, newLine);
                globExpression.push_back(tmpExpression);
                free(tmpExpression.name);
                tmpExpression.name = nullptr;
                free(tmpExpression.expression);
                tmpExpression.expression = nullptr;
                break;
            }
        }
    }
}

void copyNameOfExpression(struct Expression &tmpExpression, int size, const char *name) {
    int i;
    tmpExpression.name = (char *) malloc(sizeof(char) * size);
    for (i = 0; i < size - 1; i++) {
        tmpExpression.name[i] = name[i];
    }
    tmpExpression.name[size - 1] = '\0';
}

void copyExpressionToExpression(struct Expression &tmpExpression, int size, int position, const char *name) {
    int i, j;
    tmpExpression.expression = (char *) malloc(sizeof(char) * size);
    for (i = position, j = 0; j < size - 1; j++, i++) {
        tmpExpression.expression[j] = name[i];
    }
    tmpExpression.expression[size - 1] = '\0';
}

void printGlobalExpressions(std::vector<Expression> &globalExpression) {
    for (int i = 0; i < (int) globalExpression.size(); i++) {
        std::cout << globalExpression[i].name << " " << globalExpression[i].expression << "\n";
    }
}

