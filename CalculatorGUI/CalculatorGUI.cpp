#include "CalculatorGUI.h"
#include <string>
#include <vector>
#include <iostream>

#include "..\Calculator\ParsingFunctions.h"
#include "..\Calculator\ParsingFunctions.cpp"

#include "..\Calculator\Tree.h"
#include "..\Calculator\Tree.cpp"

CalculatorGUI::CalculatorGUI(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    
}

void CalculatorGUI::calculations()
{
    QString qt_equation = ui.ExpressionInput->text();
    std::string equation = qt_equation.toLocal8Bit().constData();
    std::vector<std::string> parsed_equation = parser(equation);

    bool checker = false;
    std::string variables_to_modify = update_variables_gui(parsed_equation, checker);
    if (checker)
    {
        const QString QtVariablesString = QString::fromStdString(variables_to_modify);
        ui.WarningScreen->setText(QtVariablesString);
        return;
    }
    std::vector<std::string> postfix_expression = postfix(parsed_equation);
    MainTree tree(postfix_expression);
    double answer = tree.calc();

    // Convert double to QT type string and output to the user;
    const QString QtAnswer = QString::number(answer);
    ui.ExpressionInput->setText(QtAnswer);
    ui.WarningScreen->setText("");
}
