
#include <bits/stdc++.h>
using namespace std;

// Function for Linear Equations methods
void jacobiMethod();
void gaussSeidelMethod();
void gaussEliminationMethod();
void gaussJordanEliminationMethod();
void luFactorizationMethod();

// Function for Non-linear Equations methods
void bisectionMethod();
void falsePositionMethod();
void secantMethod();
void newtonRaphsonMethod();

// Function for Differential Equations
void rungeKuttaMethod();

// Function for Matrix Inversion
void matrixInversion();
// Function to print the solution
void printSolution();
int main()
{
    int mainChoice, subChoice;

    while (true)
    {
        cout << "\n--- Application for Solving Equations and Inverting Matrices ---\n";
        cout << "Select the type of problem:\n";
        cout << "1. Solution of Linear Equations\n";
        cout << "2. Solution of Non-linear Equations\n";
        cout << "3. Solution of Differential Equations\n";
        cout << "4. Matrix Inversion\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> mainChoice;

        switch (mainChoice)
        {
        case 1:
            cout << "\n--- Linear Equations Methods ---\n";
            cout << "1. Jacobi Iterative Method\n";
            cout << "2. Gauss-Seidel Iterative Method\n";
            cout << "3. Gauss Elimination\n";
            cout << "4. Gauss-Jordan Elimination\n";
            cout << "5. LU Factorization\n";
            cout << "Enter your choice: ";
            cin >> subChoice;

            switch (subChoice)
            {
            case 1:
                jacobiMethod();
                break;
            case 2:
                gaussSeidelMethod();
                break;
            case 3:
                gaussEliminationMethod();
                break;
            case 4:
                gaussJordanEliminationMethod();
                break;
            case 5:
                luFactorizationMethod();
                break;
            default:
                cout << "Invalid choice for Linear Equations.\n";
                break;
            }
            break;

        case 2:
            cout << "\n--- Non-linear Equations Methods ---\n";
            cout << "1. Bisection Method\n";
            cout << "2. False Position Method\n";
            cout << "3. Secant Method\n";
            cout << "4. Newton-Raphson Method\n";
            cout << "Enter your choice: ";
            cin >> subChoice;

            switch (subChoice)
            {
            case 1:
                bisectionMethod();
                break;
            case 2:
                falsePositionMethod();
                break;
            case 3:
                secantMethod();
                break;
            case 4:
                newtonRaphsonMethod();
                break;
            default:
                cout << "Invalid choice for Non-linear Equations.\n";
                break;
            }
            break;

        case 3:
            cout << "\n--- Differential Equations Methods ---\n";
            cout << "1. Runge-Kutta Method\n";
            cout << "Enter your choice: ";
            cin >> subChoice;

            if (subChoice == 1)
            {
                rungeKuttaMethod();
            }
            else
            {
                cout << "Invalid choice for Differential Equations.\n";
            }
            break;

        case 4:
            cout << "\n--- Matrix Inversion ---\n";
            matrixInversion();
            break;

        case 5:
            cout << "Exiting the application.\n";
            return 0;

        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    }
}
void printSolution(const vector<double> &x)
{
    for (int i = 0; i < x.size(); ++i)
    {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }
}
void jacobi(const vector<vector<double>> &A, const vector<double> &b, vector<double> &x)
    {
        int maxIterations = 100; double tolerance = 1e-10 ;int n = A.size();
        vector<double> x_old(n);

        for (int k = 0; k < maxIterations; ++k)
        {
            x_old = x;
            for (int i = 0; i < n; ++i)
            {
                double sigma = 0;
                for (int j = 0; j < n; ++j)
                {
                    if (i != j)
                    {
                        sigma += A[i][j] * x_old[j];
                    }
                }
                x[i] = (b[i] - sigma) / A[i][i];
            }

            double error = 0;
            for (int i = 0; i < n; ++i)
            {
                error += abs(x[i] - x_old[i]);
            }
            if (error < tolerance)
                break;
        }

        printSolution(x);
}
void gaussSeidel(const vector<vector<double>>& A, const vector<double>& b, vector<double>& x, int maxIterations = 100, double tolerance = 1e-10) {
    int n = A.size();

    for (int k = 0; k < maxIterations; ++k) {
        vector<double> x_old = x;
        for (int i = 0; i < n; ++i) {
            double sigma = 0;
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    sigma += A[i][j] * x[j];
                }
            }
            x[i] = (b[i] - sigma) / A[i][i];
        }

        double error = 0;
        for (int i = 0; i < n; ++i) {
            error += abs(x[i] - x_old[i]);
        }
        if (error < tolerance) break;
    }
    printSolution(x);
}

void gaussElimination(vector<vector<double>> A, vector<double> b, vector<double>& x) {
    int n = A.size();

    for (int i = 0; i < n; ++i) {
        for (int k = i + 1; k < n; ++k) {
            double factor = A[k][i] / A[i][i];
            for (int j = i; j < n; ++j) {
                A[k][j] -= factor * A[i][j];
            }
            b[k] -= factor * b[i];
        }
    }

    x.resize(n);
    for (int i = n - 1; i >= 0; --i) {
        x[i] = b[i];
        for (int j = i + 1; j < n; ++j) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }
    printSolution(x);
}

void gaussJordanElimination(vector<vector<double>> A, vector<double> b, vector<double>& x) {
    int n = A.size();

    for (int i = 0; i < n; ++i) {
        double pivot = A[i][i];
        for (int j = 0; j < n; ++j) {
            A[i][j] /= pivot;
        }
        b[i] /= pivot;

        for (int k = 0; k < n; ++k) {
            if (k != i) {
                double factor = A[k][i];
                for (int j = 0; j < n; ++j) {
                    A[k][j] -= factor * A[i][j];
                }
                b[k] -= factor * b[i];
            }
        }
    }

    x = b;
    printSolution(x);
}
void luFactorization(const vector<vector<double>>& A, vector<double> b, vector<double>& x) {
    int n = A.size();
    vector<vector<double>> L(n, vector<double>(n, 0)), U = A;

    for (int i = 0; i < n; ++i) {
        L[i][i] = 1;
        for (int j = i + 1; j < n; ++j) {
            L[j][i] = U[j][i] / U[i][i];
            for (int k = i; k < n; ++k) {
                U[j][k] -= L[j][i] * U[i][k];
            }
        }
    }

    vector<double> y(n);
    for (int i = 0; i < n; ++i) {
        y[i] = b[i];
        for (int j = 0; j < i; ++j) {
            y[i] -= L[i][j] * y[j];
        }
    }

    x.resize(n);
    for (int i = n - 1; i >= 0; --i) {
        x[i] = y[i];
        for (int j = i + 1; j < n; ++j) {
            x[i] -= U[i][j] * x[j];
        }
        x[i] /= U[i][i];
    }
    printSolution(x);
}


//Function Declaration


void jacobiMethod()
{
    cout << "Jacobi Iterative Method selected.\n";
    int n;
    cout << "Enter the number of equations (size of the system): ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<double> b(n), x(n, 0);

    cout << "Enter the coefficients of matrix A:" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> A[i][j];
        }
    }

    cout << "Enter the constants of vector b:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }
    jacobi(A,b,x);
} 

void gaussSeidelMethod()
{
    cout << "Gauss-Seidel Iterative Method selected.\n";
        int n;
    cout << "Enter the number of equations (size of the system): ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<double> b(n), x(n, 0);

    cout << "Enter the coefficients of matrix A:" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> A[i][j];
        }
    }

    cout << "Enter the constants of vector b:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }
    gaussSeidel(A,b,x);

}

void gaussEliminationMethod()
{
    cout << "Gauss Elimination is selected:\n";
         int n;
    cout << "Enter the number of equations (size of the system): ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<double> b(n), x(n, 0);

    cout << "Enter the coefficients of matrix A:" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> A[i][j];
        }
    }

    cout << "Enter the constants of vector b:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }
    gaussElimination(A,b,x);

}
void gaussJordanEliminationMethod()
{
    cout << "Gauss-Jordan Elimination is selected:\n";
         int n;
    cout << "Enter the number of equations (size of the system): ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<double> b(n), x(n, 0);

    cout << "Enter the coefficients of matrix A:" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> A[i][j];
        }
    }

    cout << "Enter the constants of vector b:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }
    gaussJordanElimination(A,b,x);

}
void luFactorizationMethod()
{
    cout << "LU Factorization ia selected:\n";
     int n;
    cout << "Enter the number of equations (size of the system): ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<double> b(n), x(n, 0);

    cout << "Enter the coefficients of matrix A:" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> A[i][j];
        }
    }

    cout << "Enter the constants of vector b:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }
    luFactorization(A,b,x);

    
}

void bisectionMethod()
{
    cout << "Bisection Method is selected:\n";
}
void falsePositionMethod()
{
    cout << "False Position Method is selected:\n";
}
void secantMethod()
{
    cout << "Secant Method is selected:\n";
}
void newtonRaphsonMethod()
{
    cout << "Newton-Raphson Method is selected:\n";
}

void rungeKuttaMethod()
{
    cout << "Runge-Kutta Method is selected:\n";
}

void matrixInversion()
{
    cout << "Matrix Inversion is selected:\n";
}

