#include <iostream>
#include <vector>
#include <string>
#include "Variables.h"
#include "Expression.h"
#include "PolishNotation.h"
#include "FrequencyCharacteristic.h"


using namespace std;

double getFrequency(int solution, std::vector<Variable> &variables, std::vector<Expression> &expression) {
    std::string polishNotation;
    polishNotation = createPolishNotation(expression.at(((solution % 2 == 1) ? 0 : 1)).expression);

    return polishNotationEval(polishNotation, variables);
};

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
            "6 - Zmenit kondenzator C1 a odpor R1 a vypocitat mezni frekvenci f0\n"
            "7 - Pouzit vychozi hodnoty civky L1 a odporu R1 ze souboru a vypocitat mezni frekvenci f0\n"
            "8 - Pouzit vychozi hodnoty kondenzatoru C1 a odporu R1 ze souboru a vypocitat mezni frekvenci f0\n";
}

int main(int argc, char *argv[]) {
    bool changeVariable = false;
    vector<Variable> variables;
    initMathVariable(variables);
    vector<Expression> expression;

    if (argc != 3) {
         cout << "Nevyhovuje seznam parametru programu.\n"
                         "Vlozte prosim v poradi promenne.txt a pote vzorce.txt";
         return 1;
     }

    loadVariables(argv[1], variables);
    loadExpressions(argv[2], expression);
    int **arrayFrequency = new int *[10];
    initArray(arrayFrequency, 10);
    //printArray(arrayFrequency, 10);
    int solution;
    bool stop = false;
    while (1) {
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
                if (std::cin.fail() || solutionDerivate > 8 || solutionDerivate < 1) {
                    break;
                }

                if (solutionDerivate == 1 || solutionDerivate == 2 || solutionDerivate == 5 || solutionDerivate == 6) {
                    double R_value;
                    std::cout << "Zadejte hodnotu Odporu R1\n";
                    std::cin >> R_value;
                    if (std::cin.fail()) {
                        break;
                    }
                    int index = searchVariableInVariablesStore(variables, "R1");
                    if (index == -1) {
                        break;
                    }
                    variables.at(index).value = R_value;
                    changeVariable = true;
                }
                if (solutionDerivate == 3 || solutionDerivate == 6) {
                    double C_value;
                    std::cout << "Zadejte hodnotu Odporu C1\n";
                    std::cin >> C_value;
                    if (std::cin.fail()) {
                        break;
                    }
                    int index = searchVariableInVariablesStore(variables, "C1");
                    if (index == -1) {
                        break;
                    }
                    variables.at(index).value = C_value;
                    changeVariable = true;
                }
                if (solutionDerivate == 4 || solutionDerivate == 5) {
                    double L_value;
                    std::cout << "Zadejte hodnotu Odporu L1\n";
                    std::cin >> L_value;
                    if (std::cin.fail()) {
                        break;
                    }
                    int index = searchVariableInVariablesStore(variables, "L1");
                    if (index == -1) {
                        break;
                    }
                    variables.at(index).value = L_value;
                    changeVariable = true;
                }

                std::cout << "Mezni frekvence je " << getFrequency(solutionDerivate, variables, expression) << " Hz\n";


                break;
            }
            case 2 : {
                int solutionIntegrate;
                std::cout << "Integracni clanek\n";
                printSubMenu();
                std::cin >> solutionIntegrate;
                if (std::cin.fail() || solutionIntegrate > 8 || solutionIntegrate < 1) {
                    break;
                }

                if (solutionIntegrate == 1 || solutionIntegrate == 2 || solutionIntegrate == 5 || solutionIntegrate == 6) {
                    double R_value;
                    std::cout << "Zadejte hodnotu Odporu R1\n";
                    std::cin >> R_value;
                    if (std::cin.fail()) {
                        break;
                    }
                    int index = searchVariableInVariablesStore(variables, "R1");
                    if (index == -1) {
                        break;
                    }
                    variables.at(index).value = R_value;
                    changeVariable = true;
                }
                if (solutionIntegrate == 3 || solutionIntegrate == 6) {
                    double C_value;
                    std::cout << "Zadejte hodnotu Odporu C1\n";
                    std::cin >> C_value;
                    if (std::cin.fail()) {
                        break;
                    }
                    int index = searchVariableInVariablesStore(variables, "C1");
                    if (index == -1) {
                        break;
                    }
                    variables.at(index).value = C_value;
                    changeVariable = true;
                }
                if (solutionIntegrate == 4 || solutionIntegrate == 5) {
                    double L_value;
                    std::cout << "Zadejte hodnotu Odporu L1\n";
                    std::cin >> L_value;
                    if (std::cin.fail()) {
                        break;
                    }
                    int index = searchVariableInVariablesStore(variables, "L1");
                    if (index == -1) {
                        break;
                    }
                    variables.at(index).value = L_value;
                    changeVariable = true;
                }

                std::cout << "Mezni frekvence je " << getFrequency(solutionIntegrate, variables, expression) << " Hz\n";
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

    deleteArray(arrayFrequency, 10);
    if (changeVariable) {
        std::ofstream ofs(argv[1]);
        for(int i = 2; i < variables.size(); i++) {
            ofs << variables.at(i).name << " = " << variables.at(i).value << "\n";
        }
        ofs.close();
    }

    return 0;
}