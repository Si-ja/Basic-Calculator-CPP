#include <iostream>
#include <string>
#include <stack>
#include "ParsingFunctions.h"
#include "Tree.h"

int main()
{
    // Get the mathematical expression from the user
    std::string expression;
    std::cout << "Please enter a mathematical expression: ";
    std::getline(std::cin, expression);

    // Proceed to parse it and preparing it for manipulations
    std::vector<std::string> answer = parser(expression);
    bool satisfactory = false;
    while (!satisfactory)
    {
        answer = update_variables(answer, satisfactory);
    }
    std::vector<std::string> updated_expression = postfix(answer);
    std::cout << std::endl;
    MainTree tree(updated_expression);

    // Give back the information on the mathematical expression passed
    std::cout << "Infix version: ";
    tree.check_infix();
    std::cout << "Postfix version: ";
    tree.check_postfix();
    std::cout << std::endl;

    // Give the tree like representation of the equation
    std::cout << "This is the Tree version of the expression:" << std::endl;
    tree.print();

    // Give out the results of the calculations
    std::cout 
        << std::endl 
        << "Result of the calculation: " 
        << tree.calc() 
        << std::endl;
    system("PAUSE");
    return 0;
}