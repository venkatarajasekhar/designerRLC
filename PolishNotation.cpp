#include "PolishNotation.h"

std::string createPolishNotation(std::string &infixType) {
    std::map<char, int> assessOperator;
    fillMap(assessOperator);
    std::vector<char> operatorStack;
    std::string newstring = "", tmpString = "";
    for (int i = 0; i < infixType.size(); i++) {
        if (isAlphaChar(infixType.at(i)) || isNumericChar(infixType.at(i))) {
            tmpString += infixType.at(i);
        } else if (infixType.at(i) == '(') {
            addVariable(tmpString, newstring);
            operatorStack.push_back(infixType.at(i));
        } else if (infixType.at(i) == ')') {
            if (tmpString != "") {
                addVariable(tmpString, newstring);
            }
            char topToken = operatorStack.back();
            operatorStack.pop_back();
            while (topToken != '(') {
                newstring += " ";
                newstring += topToken;
                topToken = operatorStack.back();
                operatorStack.pop_back();
            }
        } else {
            if (tmpString != "") {
                addVariable(tmpString, newstring);
                newstring += " ";
            }
            while (!operatorStack.empty() &&
                   (assessOperator[operatorStack.back()] >= assessOperator[infixType.at(i)])) {

                newstring += operatorStack.back();
                newstring += " ";

                operatorStack.pop_back();
            }

            operatorStack.push_back(infixType.at(i));
        }
    }

    while (!operatorStack.empty()) {
        newstring += " ";
        newstring += operatorStack.back();
        operatorStack.pop_back();
    }

    return newstring;
}

void addVariable(std::string & variable, std::string & final) {
    final += variable ;
    variable = "";
}

double polishNotationEval(std::string & polishNotation, std::vector<Variable> & globalVariables) {
    std::vector<double> stackValue;
    std::string tmpString = "";
    double finalResult = 0;
    for (int i = 0; i < (int) polishNotation.length(); i++) {
        if (isOperator(polishNotation.at(i))) {
            double operand1, operand2, result;
            operand1 = stackValue.back();
            stackValue.pop_back();

            operand2 = stackValue.back();
            stackValue.pop_back();
            result = calculate(polishNotation.at(i), operand2, operand1);
            stackValue.push_back(result);

        } else {
            if (polishNotation.at(i) == ' ') {
                if (tmpString != "") {
                    int index = searchVariableInVariablesStore(globalVariables, tmpString);
                    if (index == -1) {
                        stackValue.push_back(std::stod(tmpString));

                    } else {
                        stackValue.push_back(globalVariables.at(index).value);
                    }
                    tmpString = "";
                }
            } else {
                tmpString += polishNotation.at(i);
            }
        }
    }

    finalResult = stackValue.back();
    stackValue.pop_back();

    return finalResult;
}

/**
 * def postfixEval(postfixExpr):
    operandStack = Stack()
    tokenList = postfixExpr.split()

    for token in tokenList:
                else:
            operand2 = operandStack.pop()
            operand1 = operandStack.pop()
            result = doMath(token,operand1,operand2)
            operandStack.push(result)
    return operandStack.pop()
 */






double calculate(char operatorChar, double num1, double num2) {
    switch (operatorChar) {
        case  '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
    }
    return 0.0;
}






bool isAlphaChar(const char zn) {
    if ((zn >= 'A' && zn <= 'Z') || (zn >= 'a' && zn <= 'z')) {
        return true;
    }

    return false;
}

bool isNumericChar(const char zn) {
    if (zn >= '0' && zn <= '9') {
        return true;
    }

    return false;
}

bool isOperator(const char zn) {
    if (zn == '(' || zn == ')' || zn == '/' || zn == '*' || zn == '+' || zn == '-') {
        return true;
    }
    return false;
}

void fillMap(std::map<char, int> &operatorMap) {
    operatorMap['/'] = 3;
    operatorMap['*'] = 3;
    operatorMap['+'] = 2;
    operatorMap['-'] = 2;
    operatorMap['('] = 1;
    operatorMap[')'] = 1;
}