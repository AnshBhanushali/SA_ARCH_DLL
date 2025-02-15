#ifndef MATHLIBRARY_H
#define MATHLIBRARY_H

#ifdef __INTELLISENSE__
  #define MathOperations
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*ResultCallback)(double result);

MathOperations void Add(double a, double b, ResultCallback callback);
MathOperations void Subtract(double a, double b, ResultCallback callback);
MathOperations void Multiply(double a, double b, ResultCallback callback);
MathOperations void Divide(double a, double b, ResultCallback callback);
MathOperations void Modulus(int a, int b, ResultCallback callback);
MathOperations void Power(double base, double exponent, ResultCallback callback);
MathOperations void SquareRoot(double a, ResultCallback callback);

#ifdef __cplusplus
}
#endif

#endif 
