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
Run the Program:

bash
Copy code
./linear_solvers
Select a Method:

The program will display a menu. Enter the corresponding number for the method you would like to use.
Enter the System of Equations:

Enter the size of the system (number of equations).
Enter the coefficients of matrix 
𝐴
A.
Enter the constants of vector 
𝑏
b.
View Results:

The program will display the solution for the chosen method.
Methods Explained
1. Jacobi Iterative Method
The Jacobi Method is an iterative algorithm that calculates an approximate solution to a system of linear equations. For each iteration, it updates each variable by solving for it in terms of other variables from the previous iteration. It continues until the approximation reaches the desired accuracy or the maximum number of iterations.

Function: jacobiMethod()

Complexity: This method is slow for large matrices but simple to implement. Convergence depends on the properties of matrix 
𝐴
A.

2. Gauss-Seidel Iterative Method
The Gauss-Seidel Method improves on the Jacobi method by using the most recent values for variables as soon as they are available. It tends to converge faster than Jacobi and is suitable for large sparse systems.

Function: gaussSeidelMethod()

Complexity: Faster than Jacobi, especially when 
𝐴
A is diagonally dominant.

3. Gauss Elimination
The Gauss Elimination method is a direct method that transforms matrix 
𝐴
A into an upper triangular matrix by eliminating the lower elements through row operations. Once in upper triangular form, it performs back substitution to find the values of variables.

Function: gaussEliminationMethod()

Complexity: 
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

4. Gauss-Jordan Elimination
Gauss-Jordan Elimination is an extension of Gauss Elimination that reduces matrix 
𝐴
A to the identity matrix. This method finds the solution directly without requiring back substitution, making it suitable for solving systems of equations and finding matrix inverses.

Function: gaussJordanEliminationMethod()

Complexity: 
𝑂
(
𝑛
3
)
O(n 
3
 ); more computationally intensive than Gauss Elimination but can provide additional insights into matrix structure.

5. LU Factorization
LU Factorization decomposes matrix 
𝐴
A into the product of a lower triangular matrix 
𝐿
L and an upper triangular matrix 
𝑈
U. It then solves for the variables using forward substitution on 
𝐿
L and backward substitution on 
𝑈
U. This method is efficient for solving multiple systems with the same 
𝐴
A matrix but different 
𝑏
b vectors.

Function: luFactorizationMethod()

Complexity: Suitable for large systems; widely used in applications involving multiple right-hand sides with the same matrix 
𝐴
A.

Example
For a 3x3 system:

{
4
𝑥
1
+
𝑥
2
+
2
𝑥
3
=
4
3
𝑥
1
+
5
𝑥
2
+
𝑥
3
=
7
𝑥
1
+
𝑥
2
+
3
𝑥
3
=
3
⎩
⎨
⎧
​
  
4x 
1
​
 +x 
2
​
 +2x 
3
​
 =4
3x 
1
​
 +5x 
2
​
 +x 
3
​
 =7
x 
1
​
 +x 
2
​
 +3x 
3
​
 =3
​
 
Here the matrix 
𝐴
A will contain:

[
4
1
2
3
5
1
1
1
3
]
​
  
4
3
1
​
  
1
5
1
​
  
2
1
3
​
  
​
 
And the vector 
𝑏
b will contain:

[
4
7
3
]
​
  
4
7
3
​
  
​
 
The solution will be shown in the terminal for this example.
