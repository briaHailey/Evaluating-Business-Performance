/* Name: Bria Weisblat
Date: 10/24/2022
Section: 4
Assignment: Homework 4 Evaluating Business Performance
Due Date: 10/24/2022
About this project: This program to evaluates the cumulative distribution
function of the Poisson Distribution.
Assumptions: Assume that the user will only enter the proper type of data.
Assume that 'x' will always be an integer. Assume that λ will always be a
positive number.

All work below was performed by Bria Weisblat */

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
#define E 2.71828

// Function Declarations
long double factorial(long double factorialNum);
long double sum(double actualCustomers, double expectedCustomers);


// Main function
int main()
{
    double expectedCustomers;   // (λ)
    double actualCustomers;     // (x)

    // (λ)
    cout << "Enter the expected number of customers: " << endl;
    cin >> expectedCustomers;
    // (x)
    do {
        cout << "Enter the actual number of customers: " << endl;
        cin >> actualCustomers;
        if (actualCustomers > 0) {
            cout << "Possibility of less than " << actualCustomers << " customers was " << fixed << setprecision(4)
                 << sum(actualCustomers, expectedCustomers) << endl;
            if ( sum(actualCustomers, expectedCustomers) < 0.5) {
                cout << "Under optimum performance" << endl;
            }
        }
    }
    while (actualCustomers > 0);
    return 0;
}

// Function Definitions

// Returns the factorial of a number
long double factorial(long double factorialNum) {
    long double factorialAnswer = 1;
    if (factorialNum == 0) {
        factorialNum = 1;
    }
    else {
        for (int i = factorialNum; i > 0; i--) {
            factorialAnswer *= i;
        }
    }
    return factorialAnswer;
}

// Takes ‘x’ and ‘λ’ as parameters and calculates F(x,λ) using e
long double sum(double actualCustomers, double expectedCustomers){
    long double finalSum;
    for (int i = 0; i<= actualCustomers; i++) {
        long double fractionTop = pow(expectedCustomers, i);
        long double fractionBottom = factorial(i);
        long double fullFraction = fractionTop / fractionBottom;
        finalSum += fullFraction;
    }
    finalSum = finalSum * (pow(E, -expectedCustomers));
    return finalSum;
}

