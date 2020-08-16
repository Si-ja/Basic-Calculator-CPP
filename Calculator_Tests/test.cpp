#include "pch.h"
#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <iostream>

#include "..\Calculator\ParsingFunctions.h"
#include "..\Calculator\ParsingFunctions.cpp"

#include "..\Calculator\Tree.h"
#include "..\Calculator\Tree.cpp"
TEST(SanityCheck, VerificationThatTestsStartAndWork)
{
	EXPECT_EQ(0, 0);
}

TEST(Parsing, ParsingBasics)
{
	std::string input_data;
	std::vector<std::string> actual_output;
	std::vector<std::string> expected_output;

	input_data = "1 + 2";
	actual_output = parser(input_data);
	expected_output = { "1", "+", "2" };
	EXPECT_EQ(expected_output, actual_output);

	input_data = "    ( 20   * 5                )";
	actual_output = parser(input_data);
	expected_output = { "(", "20", "*", "5", ")" };
	EXPECT_EQ(expected_output, actual_output);

	input_data = "( x + ( 5 / y15 ) )";
	actual_output = parser(input_data);
	expected_output = { "(", "x", "+", "(", "5", "/", "y15", ")", ")"};
	EXPECT_EQ(expected_output, actual_output);

	input_data = "20*(3+x)";
	actual_output = parser(input_data);
	expected_output = { "20*(3+x)" };
	EXPECT_EQ(expected_output, actual_output);

	input_data = "10.42 + 20.69";
	actual_output = parser(input_data);
	expected_output = { "10.42", "+", "20.69" };
	EXPECT_EQ(expected_output, actual_output);
}

TEST(UnknownVariables, ParsingForGUI)
{
	std::vector<std::string> expression;
	std::string answer;
	bool checker;

	expression = { "1", "+", "2" };
	checker = false;
	answer = update_variables_gui(expression, checker);
	EXPECT_EQ("", answer);
	EXPECT_FALSE(checker);

	expression = { "(", "x", "*", "y2", ")" };
	checker = false;
	answer = update_variables_gui(expression, checker);
	EXPECT_EQ("x; y2; ", answer);
	EXPECT_TRUE(checker);

}

TEST(Precedents, Sanity)
{
	std::string stack_top;
	std::string expression;
	bool acquire_result;

	stack_top = "+";
	expression = "*";
	acquire_result = check_precedents(stack_top, expression);
	EXPECT_FALSE(acquire_result);


	stack_top = "+";
	expression = "+";
	acquire_result = check_precedents(stack_top, expression);
	EXPECT_TRUE(acquire_result);

	stack_top = "*";
	expression = "*";
	acquire_result = check_precedents(stack_top, expression);
	EXPECT_TRUE(acquire_result);

	stack_top = "*";
	expression = "+";
	acquire_result = check_precedents(stack_top, expression);
	EXPECT_TRUE(acquire_result);
}

TEST(PopUp, StackPoping)
{
	std::string stack_top;
	std::string expression;
	bool acquired_output;

	stack_top = "(";
	expression = ")";
	acquired_output = opening_poping(stack_top, expression);
	EXPECT_FALSE(acquired_output);

	stack_top = "+";
	expression = ")";
	acquired_output = opening_poping(stack_top, expression);
	EXPECT_TRUE(acquired_output);

	stack_top = "?";
	expression = "42";
	acquired_output = opening_poping(stack_top, expression);
	EXPECT_TRUE(acquired_output);
}

TEST(PostfixCheck, ConversionFromInfixToPostfix)
{
	std::vector<std::string> infix;
	std::vector<std::string> expected_postfix;
	std::vector<std::string> acquired_postfix;

	infix = { "1", "+", "2" };
	expected_postfix = { "1", "2", "+" };
	acquired_postfix = postfix(infix);
	EXPECT_EQ(expected_postfix, acquired_postfix);

	infix = { "42", "*", "1337", "-", "89", "+", "15", "+", "15", "+", "15" };
	expected_postfix = { "42", "1337", "*", "89", "-", "15", "+", "15", "+", "15", "+" };
	acquired_postfix = postfix(infix);
	EXPECT_EQ(expected_postfix, acquired_postfix);

	infix = { "(", "0", "*", "(", "0", "/", "0", ")", ")" };
	expected_postfix = { "0", "0", "0", "/", "*" };
	acquired_postfix = postfix(infix);
	EXPECT_EQ(expected_postfix, acquired_postfix);
}

TEST(Calculations, CorrectResults)
{
	std::vector<std::string> expression;
	MainTree tree;
	
	expression = { "1", "1", "+" };
	tree.prepare_structure(expression);
	EXPECT_EQ(tree.calc(), 2);

	expression = { "2", "3.33", "*" };
	tree.prepare_structure(expression);
	EXPECT_EQ(tree.calc(), 6.66);

	expression = { "3", "25", "25", "+", "50", "25", "-", "-", "*" };
	tree.prepare_structure(expression);
	EXPECT_EQ(tree.calc(), 75);

	expression = { "0.222", "0.444", "-" };
	tree.prepare_structure(expression);
	EXPECT_EQ(tree.calc(), -0.222);
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
