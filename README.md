# Basic Calculator in C++

This project holds a basic example of how a calculator could be built in C++. 3 components are utilized:

1. The Back-End logic of calculation operations
2. Unit tests
3. A basic GUI

## The Back-End Logic

The back-end logic is stored in the Folder `Calculator`. Class `main` is stored in the `Calculator.cpp` file. By running it, a user can enter a mathematical expression in a console, and will receive an answer to it. This section is developed in such way, to test how operations of the calculator could be stored, before implementing the whole calculative process in the GUI interface.

The calculations take place through convertsion of an infix mathematical expression into a postfix version of it. All of the functions that allow for that to happen (e.g. parsing of the expression, validating it and converting) are stored in `ParsingFunctions.cpp\h` file.

Afterwards, the expression is broken into an Expression Tree. Calculations happen based on the traversal of the tree. The tree essentially is just a class of class Nodes. The tree itself can be evaluated with an inbuilt method `print()` and can be seen used on line 34 of the `main` function. Calculations with the help of the tree happen using the inbuilt method of `calc()` and can be seen used on line 40 of the `main` function. All of the methods for the tree are stored in its class called `MainTree` and are located in the file `Tree.cpp\h`.

__IMPORTANT__:

The current system assumes several things about the mathematical expression that is entered, in order to properly function:

* A space is made between every operator, operand and variable that are entered. E.g: 1+2 should be written as 1 + 2 (the amount of spaces does not matter, only their pressence is required).
* You can enter unidentified variables in any format. E.g. `x`, `y`, `x1`, `xyz`, `123x`, etc. But they cannot be calculated or stored in memory. Therefore, the algorithm will require the user to replace them with real values.
* You can enter values with floating points. This needs to be performed by writting a `.`. E.g. 5.5 + 2.2123
* You can use opening and closing brackets to chose which calculations need to be performed in which order (as you'd do with regular math expressions). E.g.: ( 1 + 2 ) * 3
* Currently the algorithm only supports the following operators: `+`, `-`, `/`, `*` and opening and closing brackets `(`, `)`.

An example of how calculations take place and what the user is greated with when starting the back-end logic testing main function can be seen here:

![](https://github.com/Si-ja/Basic-Calculator-CPP/blob/master/Visuals/Console_EnterData.PNG "Entry Screen")

Entering an expression `( 5 + 10 ) * 3.33 / ( 4 - 1 ) and results that are provided further:

![](https://github.com/Si-ja/Basic-Calculator-CPP/blob/master/Visuals/Console_BasicExample.PNG "Basic Equation Example")

Entering an expression `x + y2 / ( 5x * 2.3 ) + abc`, which has variables instead of actual values. Those variables are requested to be updated. Safeguards are implemented and they will be requested to be updated until a value is provided (i.e. x cannot be replaced with y):

![](https://github.com/Si-ja/Basic-Calculator-CPP/blob/master/Visuals/Console_ExampleVariables.PNG "Example with Undefined Variables")

## Unit Tests

Several Unit tests are made with Google Tests package in order to allow for a swift checking of whether all of the developer functions and methods perform as expected. The only important test not implemented: checking of how the tree is drawn. All of the tests are stored in the `Calculator_Tests` folder.

Visualization of successfully ran tests:

![](https://github.com/Si-ja/Basic-Calculator-CPP/blob/master/Visuals/CurrentTests.png "Current State of Tests")

## GUI

A GUI is built with Qt framework and allows to imitate the performance of a very simple calculator. Essentially the back-end logic is migrated to it's framework, where mathematical equations can be evaluated continously with the whole code and console interface abstracted to the user. All of the source files for that are stored in the `CalculatorGUI` folder.

Do note that all of the same rules and notices that were mentioned in the Back-End logic section apply in the GUI environment.

For unknown variable inputs a seperate screen is dedicated at the bottom of the calculator, indicating whether any variables need to be changed to real values, before calculations could take place.

Example of a working GUI can be seen here:

![](https://github.com/Si-ja/Basic-Calculator-CPP/blob/master/Visuals/Calculator.gif "GUI")

## Known Issues, Concerns, Plans for the Future

---

__The Current Projects' Structure__: The real structure is more messy than would be expected. Mostly it is related to the fact that the project is broken into 3 components, which are essentially their own little projects. It's not complicated to get arround the 3 solutions, but unfortunatelly the current structure breaks the builds in some instances. The GUI only properly starts through Visual Studio, due to missing Qt .dll files in the source files, that stop the .exe file from starting properly. Unit tests as well originally compiled in such way that their solutions live in the back-end logic folder builds. 

_Current issue_: A bit of a messy structure of the code prevents the files from being easily deployable. For such reasons, primarily only source files (to the bare minimum) are included for re-building of the project in this GitHub repository.

_Goal for the future_: reshuffle the existing code into a more convenient structure.

---

__The GUI__: At the moment GUI is at its most basic format having only 1 button for making of calculations.

_Current issue_: The GUI though does it's job, it's kind of ugly and not ment for consumer bases and deployment.

_Goal for the future_: Spend more time on the components that cover graphics.

---

__Errors Handling__: Currently there are no errors handling in the code. Even though many cases that could cause an error are mitigated, but some aren't. For instance, an undefined variable cannot start from a symbols that is an operands (excpet for minus) as they are treated as special characters. Therefore, writing something as (5 + 8 ), will not tell the algorithm to treat `(5` as an unknown variable, but will crash the calculator.

_Current issue_: Errors handling is not implemented to the best of its ability, hence rather than treating some issues as soft resets to the GUI, the calculator might crash all together.

_Goals for the future_: Implement errors handling. And update Unit Tests to check their performance.

---
