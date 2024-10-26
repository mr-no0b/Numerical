#include <bits/stdc++.h>
#include "nonlinear.h"
#include "methods.h"
using namespace std;

int main()
{
    int mainChoice;

    while (true)
    {
        cout << "\n--- Application for Solving Equations and Inverting Matrices ---\n";
        cout << "Select the type of problem:\n";
        cout << "1. Solution of Linear Equations\n";
        cout << "2. Solution of Non-linear Equations\n";
        cout << "3. Solution of Differential Equations and Matrix Inversion\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> mainChoice;

        switch (mainChoice)
        {
        case 1:linear();break;
        case 2:nonlinear();break;
        case 3:last();break;
        case 4: return 0;
        default: cout<<"Wrong input\n";
        }
    }
}
