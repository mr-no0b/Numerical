#include <bits/stdc++.h>
#include "nonlinear.h"
using namespace std;
double secant(const vector<double>& eqn, int degree) {
    double x0, x1, tol;
    cout << "Enter the two initial guesses x0 and x1: ";
    cin >> x0 >> x1;
    cout << "Enter the tolerance level: ";
    cin >> tol;

    double x2, fx0, fx1;
    do {
        fx0 = evaluatePolynomial(eqn, degree, x0);
        fx1 = evaluatePolynomial(eqn, degree, x1);

        x2 = x1 - fx1 * (x1 - x0) / (fx1 - fx0);
        x0 = x1;
        x1 = x2;

    } while (std::fabs(fx1) > tol);
    return x2;
}

