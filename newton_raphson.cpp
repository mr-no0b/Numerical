#include <bits/stdc++.h>
#include "nonlinear.h"
using namespace std;

double newtonRaphson(const vector<double>& eqn, int degree) {
    double x0, tol;
    cout << "Enter the initial guess x0: ";
    cin >> x0;
    cout << "Enter the tolerance level: ";
    cin >> tol;

    double x1;
    do {
        double fx = evaluatePolynomial(eqn, degree, x0);
        double dfx = evaluateDerivative(eqn, degree, x0);
        x1 = x0 - fx / dfx;
        x0 = x1;
    } while (fabs(evaluatePolynomial(eqn, degree, x1)) > tol);

    return x1;
}

