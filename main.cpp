#include <bits/stdc++.h>
#include "nonlinear.h"
using namespace std;
int main() {
    int degree;
    cout << "Enter the degree of the polynomial: ";
    cin >> degree;
    vector<double> eqn(degree + 1);
    cout << "Enter the coefficients (highest to lowest degree):\n";
    for (int i = 0; i <= degree; i++) {
        cout << "Coefficient of x^" << (degree - i) << ": ";
        cin >> eqn[i];
    }

    int choice;
    cout << "Choose the root-finding method:\n1. Bisection\n2. Secant\n3. Newton-Raphson\n4. False Position\n";
    cin >> choice;

    double root = NAN;
    switch (choice) {
        case 1: root = bisection(eqn, degree); break;
        case 2: root = secant(eqn, degree); break;
        case 3: root = newtonRaphson(eqn, degree); break;
        case 4: root = falsePosition(eqn, degree); break;
        default: std::cerr << "Invalid choice\n"; return 1;
    }

    std::cout << "Root found: " << root << std::endl;
    return 0;
}
