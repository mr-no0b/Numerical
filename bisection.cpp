#include <bits/stdc++.h>
#include "nonlinear.h"
using namespace std;
double bisection(const vector<double>& eqn, int degree) {
    double a, b, tol;
    cout << "Enter the interval [a, b] for bisection(Separated by space): ";
    cin >> a >> b;
    cout << "Enter the tolerance level: ";
    cin >> tol;

    double mid;

    if (evaluatePolynomial(eqn, degree, a) * evaluatePolynomial(eqn, degree, b) >= 0) {
        cerr << "Error! f(a) and f(b) have the same signs.\n";
        return NAN;
    }

    while ((b - a) / 2 > tol) {
        mid = (a + b) / 2;
        double fMid = evaluatePolynomial(eqn, degree, mid);

        if (fabs(fMid) < tol) return mid;

        if (evaluatePolynomial(eqn, degree, a) * fMid < 0) b = mid;
        else a = mid;
    }
    return (a + b) / 2;
}

