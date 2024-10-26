#include <bits/stdc++.h>
#include "nonlinear.h"
using namespace std;
double falsePosition(const vector<double>& eqn, int degree) {
    double a, b, tol;
    cout << "Enter the interval [a, b]: ";
    cin >> a >> b;
    cout << "Enter the tolerance level: ";
    cin >> tol;
    double c;
    while (true) {
        double fa = evaluatePolynomial(eqn, degree, a);
        double fb = evaluatePolynomial(eqn, degree, b);

        c = (a * fb - b * fa) / (fb - fa);
        double fc = evaluatePolynomial(eqn, degree, c);

        if (fabs(fc) < tol) return c;

        if (fa * fc < 0) b = c;
        else a = c;
    }
}

