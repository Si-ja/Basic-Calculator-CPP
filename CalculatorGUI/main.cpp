#include "CalculatorGUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CalculatorGUI w;
    w.show();
    return a.exec();
}
