# Basic Calculator in C++

This project holds a basic example of how a calculator could be built in C++. 3 components are utilized here, which are described further. 

1. The Back-End logic of calculation operations
2. Unit tests
3. A basic GUI

## The Back-End Logic

The back-end logic is stored in the Folder `Calculator`. Class `main` is stored in the `Calculator.cpp` file. By running it, a user can enter a mathematical expression in a console, and will receive an answer to it. This section is developer in such a way, to test how operations of the calculator could be stored, before implementing the whole calculative process in the GUI interface.

The calculations are build on the process of converting an infix mathematical expression into a postfix. Afterwards the expression is broken into an Expression Tree. Calculations happen based on the traversal of the tree. The tree itself can be evaluated with an inbuilt method `print()` and can be seen on line 34 of the `main`. Calculations with the help of the tree happen using the inbuilt method of `calc()` and can be seen used on line 40.

__IMPORTANT__:

The current system assumes several things about the mathematical expression that is entered:

* A space is made between every operator, operand and variable that are entered. E.g: 1+2 should be written as 1 + 2 (the amount of spaces does not matter, only their pressence).
* You can enter unidentified variables in any format. E.g. x, y, x1, xyz, 123x, etc. But after the expression will be passed, the algorithm will require to replace them with real values.
* You can enter values with floating points. This needs to be performed by writting a `.`. E.g. 5.5 + 2.2123
* You can use opening and closing brackets to chose which calculations need to be performed in which order (as you'd do with regular math expressions). E.g.: ( 1 + 2 ) * 3
* Currently the algorithm only supports the following operators: `+`, `-`, `/`, `*` and opening and closing brackets `(`, `)`.

An example of how calculations take place and what the user is greated with when starting the back-end logic testing main can be seen here:

![](https://github.com/Si-ja/Basic-Calculator-CPP/blob/master/Visuals/Console_EnterData.PNG "Entry Screen")

![](https://github.com/Si-ja/Basic-Calculator-CPP/blob/master/Visuals/Console_BasicExample.PNG "Basic Equation Example")

![](https://github.com/Si-ja/Basic-Calculator-CPP/blob/master/Visuals/Console_ExampleVariables.PNG "Example with Undefined Variables")

## Unit Tests

Several Unit tests are made with Google Tests package in order to allow for a swift checking of whether all of the developer functions and methods perform as expected. The only important test not implemented: checking of how the tree is drawn.

![](https://github.com/Si-ja/Basic-Calculator-CPP/blob/master/Visuals/CurrentTests.PNG "Current State of Tests")

## GUI

A GUI is built with Qt framework and allows to imitate the performance of a very simple calculator. Essentially the back-end logic is migrated to it's framework. 

Do note that all of the same rules and notices that were mentioned in the Back-End logic section apply in the GUI environment. 

For unknown variable inputs a seperate screen is dedicated at the bottom of the calculator indicating if any variables need to be changed to real values, before calculations could take place.

Example of the working GUI can be seen here:

![](https://github.com/Si-ja/Basic-Calculator-CPP/blob/master/Visuals/Calculator.gif "GUI")

## Know Issues, Concerns, Plans for the Future

---

__The Current Project Structure__: The real structure is more messy than would be expected. Mostly it is related to the fact that the project is broken into 3 components. It's not complicated to get arround the 3 solutions, but unfortunatelly the current structure breaks the builds in some instances. The GUI only properly starts through Visual Studio, due to missing Qt .dll files and the Unit tests originally compiled in such way that their solutions live in the back-end logic folder builds. 

_Current issue_: Becuase of this, primarily only source files (to the bare minimum) are included for re-building of the project.

_Goal for the future_: reshuffle the existing code into a more convenient structure. 

---

__The GUI__: At the moment GUI is at its most basic format having only 1 button for making of calculations.

_Current issue_: Plain and simple - the GUI though does it's job, it's kind of ugly and not ment for consumer bases.

_Goal for the future_: Spend more time on the Graphical works.

---

__Errors Handling__: Currently there are no errors handling in the code. Even though many cases are expected and are mitigated for what could break the execution of the code, but some aren't. For instance, a variable cannot start from any symbols that are operands (excpet for minus) as they are treated as special characters. Therefore, writing something like (5 + 8 ), will not tell the algorithm to treat (5 as an unknown variable, but will crash the calculator.

_Current issue_: Errors handling is not implemented, hence rather than treating some issues as soft resets to the GUI, the calculator might get crashed all together.

_Goals for the future_: Implement errors handling. And update Unit Tests with that. 

---