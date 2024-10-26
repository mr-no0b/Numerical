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
`linear():` For linear equations

`nonlinear():` For non-linear equations

`last():` For differential equations and matrix inversion

`exit:` To close the program

Example Menu Output:

```markdown
Application for Solving Equations and Inverting Matrices 
Select the type of problem:
1. Solution of Linear Equations
2. Solution of Non-linear Equations
3. Solution of Differential Equations and Matrix Inversion**
4. Exit
Enter your choice: _
```

## methods.h

The methods.h header file declares the three main functions that link main.cpp to specific solution methods:

nonlinear(): Directs to the non-linear equation-solving methods.

linear(): Directs to the linear equation-solving methods.

last(): Directs to differential equations and matrix inversion functions.

# Solution of Linear Equations

This C++ program demonstrates different numerical methods for solving systems of linear equations. The program allows the user to select from the following methods:

**1. Jacobi Iterative Method**

**2. Gauss-Seidel Iterative Method**

**3. Gauss Elimination**

**4. Gauss-Jordan Elimination**

**5. LU Factorization**

Each method has a dedicated function and will prompt the user for the necessary matrix and vector inputs to solve a system of equations of the form:

\[
Ax = b
\]

where \( A \) is a matrix of coefficients, \( x \) is the vector of variables, and \( b \) is the constant vector.

## How to Use

1. **Compile the Code**: 
   ```bash
   g++ -o linear_solvers linear_solvers.cpp
**Run the Program:**


Select a Method:
The program will display a menu. Enter the corresponding number for the method you would like to use.

Enter the System of Equations:

Enter the size of the system (number of equations).

Enter the coefficients of matrix 𝐴

Enter the constants of vector b.

**View Results:**

The program will display the solution for the chosen method.

## Methods Explained

**1. Jacobi Iterative Method**

The Jacobi Method is an iterative algorithm that calculates an approximate solution to a system of linear equations. For each iteration, it updates each variable by solving for it in terms of other variables from the previous iteration. It continues until the approximation reaches the desired accuracy or the maximum number of iterations.

**Function: jacobiMethod()**

**Complexity:**
This method is slow for large matrices but simple to implement. Convergence depends on the properties of matrix 
𝐴.

**2. Gauss-Seidel Iterative Method**

The Gauss-Seidel Method improves on the Jacobi method by using the most recent values for variables as soon as they are available. It tends to converge faster than Jacobi and is suitable for large sparse systems.

**Function: gaussSeidelMethod()**

**Complexity:**
Faster than Jacobi, especially when 𝐴 is diagonally dominant.

**3. Gauss Elimination**

The Gauss Elimination method is a direct method that transforms matrix 𝐴 into an upper triangular matrix by eliminating the lower elements through row operations. Once in upper triangular form, it performs back substitution to find the values of variables.

**Function: gaussEliminationMethod()**

**Complexity:**

𝑂
(
𝑛
3
)
O(n 
3
 ) for 
𝑛
n-dimensional matrices; suitable for small to medium-sized systems.

**4. Gauss-Jordan Elimination**

Gauss-Jordan Elimination is an extension of Gauss Elimination that reduces matrix 𝐴 to the identity matrix. This method finds the solution directly without requiring back substitution, making it suitable for solving systems of equations and finding matrix inverses.

**Function: gaussJordanEliminationMethod()**

**Complexity:**

𝑂
(
𝑛
3
)
O(n 
3
 ); more computationally intensive than Gauss Elimination but can provide additional insights into matrix structure.
**5. LU Factorization**

LU Factorization decomposes matrix 𝐴 into the product of a lower triangular matrix 
𝐿 and an upper triangular matrix U. It then solves for the variables using forward substitution on 
𝐿 and backward substitution on U. This method is efficient for solving multiple systems with the same 
𝐴 matrix but different b vectors.

**Function: luFactorizationMethod()**

**Complexity:**
Suitable for large systems; widely used in applications involving multiple right-hand sides with the same matrix 𝐴

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

## false_position.cpp
The False Position Method uses linear interpolation to approximate the root:

Input: Requests an interval [a, b] and tolerance.
Calculation: Uses the formula c = (a * f(b) - b * f(a)) / (f(b) - f(a)) for interpolation.
Update: Narrows interval by checking f(a) and f(c).
Output: Returns c when tolerance is met.

## secant.cpp
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


# Runge_Kutta Method and Matrix Inversion :

This project demonstrates numerical methods for solving ordinary differential equations (ODEs) and performing matrix inversion. The code allows users to calculate approximate solutions to ODEs using the Runge-Kutta method and to compute the inverse of a square matrix using Gaussian elimination with row operations.


## Overview

This project contains two main functionalities:

1. *Runge-Kutta Method*: A fourth-order method to approximate solutions for differential equations.
2. *Matrix Inversion*: A method to calculate the inverse of a square matrix by Gaussian elimination.

The code prompts the user to choose either method and accepts inputs for necessary parameters.

## Methods and Explanations

### Function f(x, y)

This function calculates the value of \( f(x, y) = x^2 + y^2 \). It represents the differential equation \( y' = f(x, y) \), which is used in the Runge-Kutta method.

*Parameters*:
- x: The x-coordinate.
- y: The y-coordinate.

*Returns*:
- The result of \( x^2 + y^2 \).

### Function rungeKuttaMethod

This function uses the fourth-order Runge-Kutta method to approximate the solution of a differential equation for given initial values.

*How It Works*:

1. *Input Values*:
   - Initial values for x0 and y0, and the target xn at which to approximate y.
   - The number of intervals intv to divide the range \([x_0, x_n]\), which determines the step size h.

2. *Calculations*:
   - The step size h is calculated as \( (x_n - x_0) / \text{intv} \).
   - For each interval, intermediate values (k1, k2, k3, and k4) are computed to update y0 and x0 iteratively.

3. *Output*:
   - Displays the approximate value of y at xn.

*Parameters*: None (inputs are taken interactively).

### Function swap_rows

This helper function swaps two rows of an augmented matrix, which is used in the matrix inversion process to ensure a non-zero pivot element.

*Parameters*:
- a: The augmented matrix of size \(10 \times 20\).
- row1, row2: The row indices to swap.
- n: The size of the matrix.

*Returns*: None.

### Function matrixInversion

This function calculates the inverse of a square matrix using Gaussian elimination with partial pivoting.

*How It Works*:

1. *Input*:
   - The matrix dimension n and matrix elements from the user.

2. *Augmented Matrix*:
   - An identity matrix is appended to the input matrix, creating an augmented matrix.

3. *Row Operations*:
   - Partial pivoting is performed to handle zero elements in the diagonal.
   - Rows are scaled and subtracted to convert the matrix into row-reduced echelon form, making the original matrix become the identity matrix and the augmented part the inverse.

4. *Output*:
   - If the matrix is singular (non-invertible), an error message is displayed.
   - Otherwise, the function displays the inverse matrix.

*Parameters*: None (inputs are taken interactively).

### Function last

This function serves as the main driver for the program, allowing users to select either the Runge-Kutta method or matrix inversion.

*How It Works*:
1. Displays a menu and prompts the user to choose an option.
2. Calls either rungeKuttaMethod or matrixInversion based on the user's choice.

*Parameters*: None (inputs are taken interactively).



