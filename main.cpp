#include <iostream>
#include <vector>
#include "Variables.h"
#include "Expression.h"
#include "PolishNotation.h"


using namespace std;

int main(int argc, char *argv[]) {
    vector<Variable> variables;
    initMathVariable(variables);
    vector<Expression> expression;

    /* if (argc != 3) {
         cout << "Nevyhovuje seznam parametru programu.\n"
                         "Vlozte prosim v poradi promenne.txt a pote vzorce.txt";
         return 1;
     }
 */
    loadVariables("/Users/tomichi/ClionProjects/designerRLC/variable.txt", variables);
    cout << "tisk promomennych ";
    printGlobalVariable(variables);

    cout << searchVariableInVariablesStore(variables, "R1") << "\n" << searchVariableInVariablesStore(variables, "C2");

    cout << "\n";
    loadExpressions("/Users/tomichi/ClionProjects/designerRLC/expression.txt", expression);
    printGlobalExpressions(expression);

    std::string pokus = createPolishNotation(expression.at(0).expression);

    cout << polishNotationEval(pokus,variables) << "\n";

    //parseExpression(expression[0].expression);


    return 0;
}