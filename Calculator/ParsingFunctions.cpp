#include "ParsingFunctions.h"
#include <iostream>
#include <string>
#include <vector>
#include <stack>

std::vector<std::string> parser(std::string expression)
{
    std::string temp_value;
    std::vector<std::string> accumulator;
    for (char value : expression)
    {
        if (value == ' ')
        {
            if (temp_value != "")
            {
                accumulator.push_back(temp_value);
                temp_value = "";
            }
        }
        else
        {
            temp_value = temp_value + value;
        }
    }
    accumulator.push_back(temp_value);
    return accumulator;
}

std::vector<std::string> update_variables(std::vector<std::string> expression, bool& satisfactory)
{
    std::string characters_ignore = "0123456789+-*/().";
    std::string value;
    satisfactory = true;
    for (int i = 0; i < expression.size(); i++)
    {
        std::size_t found = expression[i].find_first_not_of(characters_ignore);
        if (found != std::string::npos)
        {
            satisfactory = false;
            std::cout
                << "The entered variable ["
                << expression[i]
                << "] is not defined. Please define it: ";
            std::cin >> value;
            expression[i] = value;
        }
    }
    return expression;
}

std::string update_variables_gui(std::vector<std::string> expression, bool& checker)
{
    std::string characters_ignore = "0123456789+-*/().";
    checker = false;
    std::string output;
    for (int i = 0; i < expression.size(); i++)
    {
        std::size_t found = expression[i].find_first_not_of(characters_ignore);
        if (found != std::string::npos)
        {
            checker = true;
            output = output + expression[i] + "; ";
        }
    }
    return output;
}

bool check_precedents(std::string stack_top, std::string expression)
{
    if ((stack_top == "*" || stack_top == "/") && (expression == "+" || expression == "-"))
    {
        return true;
    }
    else if ((stack_top == "*" || stack_top == "/") && (expression == "*" || expression == "/"))
    {
        return true;
    }
    else if ((stack_top == "+" || stack_top == "-") && (expression == "+" || expression == "-"))
    {
        return true;
    }
    return false;
}

bool opening_poping(std::string stack_top, std::string expression)
{
    if (stack_top == "(" && expression == ")")
    {
        return false;
    }
    return true;
}

std::vector<std::string> postfix(std::vector<std::string> infix)
{
    std::vector<std::string> postfix;
    std::stack<std::string> stack;
    std::string output;
    std::string t;

    for (int i = 0; i < infix.size(); i++)
    {
        std::string entry = infix[i];
        if (entry != "+" && entry != "-" && entry != "*" && entry != "/" && entry != ")" && entry != "(")
        {
            postfix.push_back(entry);
        }
        else if (entry == "+" || entry == "-" || entry == "*" || entry == "/")
        {
            while (!stack.empty() && check_precedents(stack.top(), entry))
            {
                postfix.push_back(stack.top());
                stack.pop();
            }
            stack.push(entry);
        }
        else if (entry == "(")
        {
            stack.push(entry);
        }
        else if (entry == ")")
        {
            while (!stack.empty() && opening_poping(stack.top(), entry))
            {
                postfix.push_back(stack.top());
                stack.pop();
            }
            stack.pop();
        }
    }
    while (!stack.empty())
    {
        postfix.push_back(stack.top());
        stack.pop();
    }
    return postfix;
}