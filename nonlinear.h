#ifndef NONLINEAR_H
#define NONLINEAR_H
#include<bits/stdc++.h>
double bisection(const vector<double>& eqn, int degree);
double secant(const vector<double>& eqn, int degree);
double newtonRaphson(const vector<double>& eqn, int degree);
double falsePosition(const vector<double>& eqn, int degree);
double evaluatePolynomial(const vector<double>& eqn, int degree, double x);
double evaluateDerivative(const vector<double>& eqn, int degree, double x);
#endif

