#include <bits/stdc++.h>
#include "nonlinear.h"
using namespace std;
double evaluatePolynomial(const vector<double>& eqn, int degree, double x) {
    double result = 0.0;
    for (int i = 0; i <= degree; i++) {
        result += eqn[i] * pow(x, degree - i);
    }
    return result;
}
double evaluateDerivative(const vector<double>& eqn, int degree, double x) {
    double result = 0.0;
    for (int i = 0; i < degree; i++) {
        result += eqn[i] * (degree - i) * pow(x, degree - i - 1);
    }
    return result;
}

