# Console Application for Solving Equations and Matrix Inversion
This C++ console application provides numerical methods for solving linear and non-linear equations, as well as differential equations and matrix inversion. Users can select a problem type from a menu to access various solution methods implemented in separate files.

## Project Structure
The application consists of three main modules:

Solution of Linear Equations
Solution of Non-linear Equations
Differential Equations and Matrix Inversion
Each module is managed by dedicated functions within main.cpp and accessed based on the user’s menu selection.

Code Overview
main.cpp
The main.cpp file is the central control of the application. It includes the main menu and navigates between linear and non-linear equations, differential equations, and matrix inversion. Users are presented with options to:

Choose a problem type (e.g., linear or non-linear equations)
Execute the chosen method using function calls:
linear(): For linear equations
nonlinear(): For non-linear equations
last(): For differential equations and matrix inversion
exit: To close the program
Example Menu Output:

## Application for Solving Equations and Inverting Matrices 
**Select the type of problem:**

**1. Solution of Linear Equations**

**2. Solution of Non-linear Equations**

**3. Solution of Differential Equations and Matrix Inversion**

**4. Exit**

**Enter your choice: _**

## methods.h

The methods.h header file declares the three main functions that link main.cpp to specific solution methods:

nonlinear(): Directs to the non-linear equation-solving methods.
linear(): Directs to the linear equation-solving methods.
last(): Directs to differential equations and matrix inversion functions.

# Non-linear Equations

The Non-linear Equations module in nonlinear.cpp provides users with a choice of root-finding methods for polynomial equations of a given degree. The program includes implementations for:

**Bisection Method**

**Secant Method**

**Newton-Raphson Method**

**False Position Method**

**nonlinear.h**

This header file declares all functions required for non-linear equation solving, including:

bisection(): Implements the Bisection Method.
secant(): Implements the Secant Method.
newtonRaphson(): Implements the Newton-Raphson Method.
falsePosition(): Implements the False Position Method.
evaluatePolynomial(): Evaluates the polynomial at a given point.
evaluateDerivative(): Evaluates the polynomial’s derivative at a given point.
Root-Finding Method Implementations
## nonlinear.cpp
The nonlinear() function prompts the user for polynomial degree, coefficients, and root-finding method choice. It:

Captures Polynomial Degree and Coefficients: Reads user input for polynomial coefficients.
Presents Method Choices: Allows users to select one of four root-finding methods.
Executes the Chosen Method: Calls the appropriate function for solving the polynomial.
Displays the Result: Outputs the calculated root.
## bisection.cpp
The Bisection Method iteratively halves an interval [a, b] to narrow down the root location. The steps are:

Input: Requests an interval [a, b] and a tolerance level.
Check: Ensures f(a) and f(b) have opposite signs.
Loop: Finds the midpoint, narrows the interval based on function values, and repeats until convergence.
Result: Returns the midpoint as the approximate root.
##false_position.cpp
The False Position Method uses linear interpolation to approximate the root:

Input: Requests an interval [a, b] and tolerance.
Calculation: Uses the formula c = (a * f(b) - b * f(a)) / (f(b) - f(a)) for interpolation.
Update: Narrows interval by checking f(a) and f(c).
Output: Returns c when tolerance is met.
##secant.cpp
The Secant Method finds roots through successive linear approximations:

Input: Requests two initial guesses (x0, x1) and tolerance.
Iteration: Updates approximations with x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0)).
Convergence: Continues until f(x1) is within tolerance.
Result: Outputs x2 as the approximate root.
## newton_raphson.cpp
The Newton-Raphson Method iteratively refines an initial guess:


Input: Requests an initial guess (x0) and tolerance.
Formula: Uses x1 = x0 - f(x0) / f'(x0) for approximation.
Update: Iteratively refines guess with calculated derivative.
Result: Returns x1 as the approximate root.

### Helper Functions in `eva.cpp`
evaluatePolynomial(): Computes polynomial value by summing terms a_i * x^(degree - I).
evaluateDerivative(): Computes derivative by summing terms a_i * (degree - i) * x^(degree - i - 1).


