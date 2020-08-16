#pragma once
#include <string>
#include <iostream>
#include <vector>

class MainTree
{
    private:
        /// <summary>
        /// A struct for generating an ever growing Expression Tree (essentially this is a Node,
        /// that holds more nodes inside of self in own leafs.
        /// </summary>
        struct ExpressionTree 
        {
            std::string value;
            ExpressionTree* left, * right;
        };

        /// <summary>
        /// Function that checks if the processed value is a mathematical operator.
        /// </summary>
        /// <param name="c">Value to evealuate</param>
        /// <returns>True if something is a  +, -, * or /. False in all other cases.</returns>
        bool isOperator(std::string c);

        /// <summary>
        /// Method that builds the expression tree from a known postfix representation of a
        /// mathematical expression.
        /// </summary>
        /// <param name="postfix">Postifx expression of a mathematical expression processed.</param>
        /// <returns>Retures a build Expression Tree</returns>
        ExpressionTree* constructTree(std::vector<std::string> postfix);

        /// <summary>
        /// New node generator in an expression tree.
        /// </summary>
        /// <param name="value">Value at the root of the node.</param>
        /// <returns>An expression tree (part of the bigger one)</returns>
        ExpressionTree* newNode(std::string value);

        /// <summary>
        /// Method that traverses the Expression Tree and rebuild the infix version of the passed postfix expression.
        /// </summary>
        /// <param name="Tree">Expression Tree that needs to be traversed</param>
        void inorder(ExpressionTree* Tree);

        /// <summary>
        /// Method that allows for printing of the structure of the Expression Tree.
        /// </summary>
        /// <param name="root">Root value of a Tree.</param>
        /// <param name="space">How deep the tree already went for the root of the tree passed</param>
        void print2DUtil(ExpressionTree* root, int space);

        /// <summary>
        /// Assistance method to the print2DUtil that allows for going deeper into the tree
        /// For printing purposes.
        /// </summary>
        /// <param name="root">Root value of the tree (or rather even to say Node)</param>
        void print2D(ExpressionTree* root);

        /// <summary>
        /// This is a back end logic of the calculations that happen when the tree is traversed.
        /// </summary>
        /// <param name="root">Expression Trees root node.</param>
        /// <returns>An answer in a form of a double.</returns>
        double back_end_calc(ExpressionTree* root);

        /// <summary>
        /// Expression Tree as is.
        /// </summary>
        ExpressionTree* tree;

        /// <summary>
        /// Postfix from which the tree is generated. Kept for reference
        /// </summary>
        std::vector<std::string> postfix;
    public:
        /// <summary>
        /// Modified constructor. Made to allow for a faster building of the tree and populating
        /// of all the needed information in the class, to allow for a smooth flow of work further.
        /// </summary>
        /// <param name="postfix">Postifx from which the whole Expression Tree is build.</param>
        /// <returns>A class of Main Tree</returns>
        MainTree(std::vector<std::string> postfix);

        /// <summary>
        /// Allows for an explicit call to a destructor.
        /// <summary>
        ~MainTree();

        /// <summary>
        /// Default constructor that does not load any logic upfront.
        /// </summary>
        /// <returns>A default constructor that does not have any data prepared with self.</returns>
        MainTree();

        /// <summary>
        /// A method that is present replacing the modified constructor.
        /// Essentially - call this method with a postfix expression to 
        /// change the structure of an existing object, which is an instance
        /// of the MainTree class.
        /// </summary>
        /// <param name="postfix">A postfix expression for calculations.</param>
        void prepare_structure(std::vector<std::string> postfix);

        /// <summary>
        /// Method that allows to check what approximate infix form is of the postfix expression.
        /// </summary>
        void check_infix();

        /// <summary>
        /// Method that allows to check what postfix parameter was pased into the constructor.
        /// </summary>
        void check_postfix();

        /// <summary>
        /// Method that prints sideways the structure of the Expression Tree generated.
        /// </summary>
        void print();

        /// <summary>
        /// Calculate the actual value of the postifx input data throuh a hidden back_end_logic
        /// calculation method, that is privated.
        /// </summary>
        /// <returns>A double value (it is assumed not only integers can be calculated)</returns>
        double calc();
};
