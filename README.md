# Solution of Linear Equations

This C++ program demonstrates different numerical methods for solving systems of linear equations. The program allows the user to select from the following methods:

1. Jacobi Iterative Method
2. Gauss-Seidel Iterative Method
3. Gauss Elimination
4. Gauss-Jordan Elimination
5. LU Factorization

Each method has a dedicated function and will prompt the user for the necessary matrix and vector inputs to solve a system of equations of the form:

\[
Ax = b
\]

where \( A \) is a matrix of coefficients, \( x \) is the vector of variables, and \( b \) is the constant vector.

## How to Use

1. **Compile the Code**: 
   ```bash
   g++ -o linear_solvers linear_solvers.cpp
