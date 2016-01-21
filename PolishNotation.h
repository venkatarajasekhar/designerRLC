#ifndef DESIGNERRLC_POLISHNOTATION_H
#define DESIGNERRLC_POLISHNOTATION_H

#include <string>
#include <vector>
#include <map>
#include "Variables.h"


std::string createPolishNotation(std::string & infixType);
void addVariable(std::string & variable, std::string & final);
double calculate(char operatorChar, double num1, double num2);
double polishNotationEval(std::string & polishNotation, std::vector<Variable> & globalVariables);

void fillMap(std::map<char,int> &operatorMap);
bool isAlphaChar(const char zn);
bool isNumericChar(const char zn);
bool isOperator(const char zn);

#endif //DESIGNERRLC_POLISHNOTATION_H
