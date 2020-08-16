#include "Tree.h"
#include <iostream>
#include <string>
#include <vector>
#include <stack>

bool MainTree::isOperator(std::string c)
{
    if (c == "+" || c == "-" || c == "*" || c == "/")
    {
        return true;
    }
    return false;
}
MainTree::ExpressionTree* MainTree::constructTree(std::vector<std::string> postfix)
{
    std::stack<ExpressionTree*> stack;
    ExpressionTree* Tree, * Tree1, * Tree2;

    // Traverse through every character of the input expression
    for (int i = 0; i < postfix.size(); i++)
    {
        if (!isOperator(postfix[i]))
        {
            Tree = newNode(postfix[i]);
            stack.push(Tree);
        }
        else
        {
            Tree = newNode(postfix[i]);
            Tree1 = stack.top();
            stack.pop();
            Tree2 = stack.top();
            stack.pop();

            Tree->right = Tree1;
            Tree->left = Tree2;

            stack.push(Tree);
        }
    }
    Tree = stack.top();
    stack.pop();
    return Tree;
}
MainTree::ExpressionTree* MainTree::newNode(std::string value)
{
    ExpressionTree* temp = new ExpressionTree;
    temp->left = temp->right = NULL;
    temp->value = value;
    return temp;
}
void MainTree::inorder(ExpressionTree* Tree)
{
    if (Tree)
    {
        inorder(Tree->left);
        std::cout << Tree->value;
        inorder(Tree->right);
    }
}
void MainTree::print2DUtil(ExpressionTree* root, int space)
{
    const int COUNT = 6;
    // Empty root scenario  
    if (root == NULL)
        return;

    // Increase distance between levels  
    space += COUNT;

    // Process right child first  
    print2DUtil(root->right, space);

    // Print current node after space count  
    for (int i = COUNT; i < space; i++)
    {
        std::cout << " ";
    }

    std::cout
        << "["
        << root->value
        << "]"
        << std::endl;

    // Process left child  
    print2DUtil(root->left, space);
}
void MainTree::print2D(ExpressionTree* root)
{
    // Pass initial space count as 0  
    print2DUtil(root, 0);
}
double MainTree::back_end_calc(ExpressionTree* root)
{
    if (!root)
    {
        return 0;
    }
    // Transform a leaf value into a double
    if (!root->left && !root->right)
    {
        return std::stod(root->value);
    }

    double left_value = back_end_calc(root->left);
    double right_value = back_end_calc(root->right);

    // Computationla logic:
    if (root->value == "+")
    {
        return left_value + right_value;
    }
    if (root->value == "-")
    {
        return left_value - right_value;
    }
    if (root->value == "/")
    {
        return left_value / right_value;
    }
    if (root->value == "*")
    {
        return left_value * right_value;
    }
}

MainTree::MainTree(std::vector<std::string> postfix)
{
    this->postfix = postfix;
    this->tree = this->constructTree(this->postfix);
}
MainTree::~MainTree()
{

}
MainTree::MainTree()
{

}
void MainTree::prepare_structure(std::vector<std::string> postfix)
{
    this->postfix = postfix;
    this->tree = this->constructTree(this->postfix);
}
void MainTree::check_infix()
{
    this->inorder(this->tree);
    std::cout << std::endl;
}
void MainTree::check_postfix()
{
    for (std::string value : this->postfix)
    {
        std::cout << value;
    }
    std::cout << std::endl;
}
void MainTree::print()
{
    this->print2D(this->tree);
    std::cout << std::endl;
}
double MainTree::calc()
{
    return this->back_end_calc(this->tree);
}