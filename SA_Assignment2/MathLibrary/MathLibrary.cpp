#include "MathLibrary.h"
#include <iostream>
#include <cmath>

using namespace std;

extern "C" {

MathOperations void Add(double a, double b, ResultCallback callback) {
    cout << "Addition Operation" << endl;
    double result = a + b;
    callback(result);
}

MathOperations void Subtract(double a, double b, ResultCallback callback) {
    cout << "Subtraction Operation" << endl;
    double result = a - b;
    callback(result);
}

MathOperations void Multiply(double a, double b, ResultCallback callback) {
    cout << "Multiplication Operation" << endl;
    double result = a * b;
    callback(result);
}

MathOperations void Divide(double a, double b, ResultCallback callback) {
    cout << "Division Operation" << endl;
    if (b == 0) {
        cout << "Error: Division by zero." << endl;
        callback(0);
        return;
    }
    double result = a / b;
    callback(result);
}

MathOperations void Modulus(int a, int b, ResultCallback callback) {
    cout << "Modulus Operation" << endl;
    if (b == 0) {
        cout << "Error: Division by zero in modulus." << endl;
        callback(0);
        return;
    }
    double result = a % b;
    callback(result);
}

MathOperations void Power(double base, double exponent, ResultCallback callback) {
    cout << "Power Operation" << endl;
    double result = pow(base, exponent);
    callback(result);
}

MathOperations void SquareRoot(double a, ResultCallback callback) {
    cout << "Square Root Operation" << endl;
    if (a < 0) {
        cout << "Error: Square root of a negative number." << endl;
        callback(0);
        return;
    }
    double result = sqrt(a);
    callback(result);
}

}
