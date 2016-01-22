#include <iostream>
#include <vector>
#include "Variables.h"
#include "Expression.h"
#include "PolishNotation.h"
#include "FrequencyCharacteristic.h"


using namespace std;

void printMainMenu() {
    std::cout << "Vyberte kterou možnost chcete zvolit\n"
            "1 - Navrhnout derivacni clanek\n"
            "2 - Navrhnout integracni clanek\n"
            "3 - Ukoncit program\n";
}

void printSubMenu() {
    std::cout << "Vyberte volbu\n"
            "1 - Zmenit pouze odpor R1 a vypocitat mezni frekvenci f0 s C1\n"
            "2 - Zmenit pouze odpor R1 a vypocitat mezni frekvenci f0 s L1\n"
            "3 - Zmenit pouze kondenzator C1 a vypocitat mezni frekvenci f0 s R1\n"
            "4 - Zmenit pouze civku L1 a vypocitat mezni frekvenci f0 s R1\n"
            "5 - Zmenit civku L1 a odpor R1 a vypocitat mezni frekvenci f0\n"
            "6 - Zmenit kondenzator C1 a odpor R1 a vypocitat mezni frekvenci f0\n";
            "7 - Pouzit vychozi hodnoty civky L1 a odporu R1 ze souboru a vypocitat mezni frekvenci f0\n";
            "8 - Pouzit vychozi hodnoty kondenzatoru C1 a odporu R1 ze souboru a vypocitat mezni frekvenci f0\n";
}

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
    loadExpressions("/Users/tomichi/ClionProjects/designerRLC/expression.txt", expression);
    int **arrayFrequency = new int *[10];
    initArray(arrayFrequency, 10);
    //printArray(arrayFrequency, 10);
    int solution;
    bool stop = false;
    while(1) {
        if (stop) {
            break;
        }
        printMainMenu();
        std::cin >> solution;
        if (std::cin.fail()) {
            break;
        }
        switch (solution) {
            case 1 : {
                std::cout << "Derivacni clanek\n";
                int solutionDerivate;
                printSubMenu();
                std::cin >> solutionDerivate;
                if (std::cin.fail()) {
                    break;
                }


                break;
            }
            case 2 : {
                int solutionIntegrate;
                std::cout << "Integracni clanek\n";
                printSubMenu();
                std::cin >> solutionIntegrate;
                if (std::cin.fail()) {
                    break;
                }
                break;
            }

            case 3 : {
                stop = true;
                break;
            }

            default : {
                break;
            }
        }
    }

    //printGlobalVariable(variables);

    //cout << searchVariableInVariablesStore(variables, "R1") << "\n" << searchVariableInVariablesStore(variables, "C2");

    //printGlobalExpressions(expression);

    //std::string pokus = createPolishNotation(expression.at(0).expression);

    //cout << polishNotationEval(pokus,variables) << "\n";

    //parseExpression(expression[0].expression);
    deleteArray(arrayFrequency, 10);

    return 0;
}