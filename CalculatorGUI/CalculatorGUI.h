#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CalculatorGUI.h"

class CalculatorGUI : public QMainWindow
{
    Q_OBJECT

public:
    CalculatorGUI(QWidget *parent = Q_NULLPTR);

private:
    Ui::CalculatorGUIClass ui;

    private slots:
        void calculations();

};
