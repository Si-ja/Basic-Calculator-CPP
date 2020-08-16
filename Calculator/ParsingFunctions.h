#pragma once
#include <string>
#include <vector>
#include <stack>

/// <summary>
/// Parse the original string of input data into seperate expressions.
/// </summary>
/// <param name="expression">A mathematical epxression</param>
/// <returns>A vector of strings, each containing a variable, an operator or an operand</returns>
std::vector<std::string> parser(std::string expression);

/// <summary>
/// Function that makes sure that all the variables entered into the input expression
/// are valid.
/// </summary>
/// <param name="expression">Parsed expression.</param>
/// <param name="satisfactory">A reference point that indicates whether the expression is satsifactory for calculations or not.</param>
/// <returns>And updated parsed expression with fixed variables. The reference point [satisfactory] updates through a reference pointer.</returns>
std::vector<std::string> update_variables(std::vector<std::string> expression, bool& satisfactory);

/// <summary>
/// Function that checks in a gui environment if all of the entered values
/// are feasible to be used in a mathematical expression (i.e. if there are
/// no unidentified variables present in the equation)
/// </summary>
/// <param name="checker">A verifying variable that makes sure whether unidentified variables are present or not</param>
/// <param name="expression">A parased mathematical expression</param>
/// <returns>A string, identifying which variables need to be </returns>
std::string update_variables_gui(std::vector<std::string> expression, bool& checker);

/// <summary>
/// Check the precedents of operators in the stack in comparison to the the one evaluated.
/// </summary>
/// <param name="stack_top">What comes on the top of the stack.</param>
/// <param name="expression">What expression is compared to.</param>
/// <returns>Whether true or false in respect to if the evaluated operator has higher precedents or not.</returns>
bool check_precedents(std::string stack_top, std::string expression);

/// <summary>
/// Function that helps to verify whether poping from stack should continue or stop,
/// if there are opening and closing parenthesis.
/// </summary>
/// <param name="stack_top">Current variables in the top of the stack.</param>
/// <param name="expression">Current expression being passed to the algorithm.</param>
/// <returns>Either false or true</returns>
bool opening_poping(std::string stack_top, std::string expression);

/// <summary>
/// A funciton that should turn an infix expression into a postfix
/// </summary>
/// <param name="infix">An infix expression.</param>
/// <returns>A postfix expression.</returns>
std::vector<std::string> postfix(std::vector<std::string> infix);