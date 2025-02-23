#include <iostream>
#ifdef _WIN32
  #include <windows.h>
#else
  #include <dlfcn.h>
#endif
#include "MathLibrary.h"  

using namespace std;

typedef void (*AddFunc)(double, double, ResultCallback);
typedef void (*SubtractFunc)(double, double, ResultCallback);
typedef void (*MultiplyFunc)(double, double, ResultCallback);
typedef void (*DivideFunc)(double, double, ResultCallback);
typedef void (*ModulusFunc)(int, int, ResultCallback);
typedef void (*PowerFunc)(double, double, ResultCallback);
typedef void (*SquareRootFunc)(double, ResultCallback);

void Result(double result) {
    cout << "Result: " << result << "\n" << endl;
}

int main() {
#ifdef _WIN32
#else
    void* hLib = dlopen("./libMathLibrary.dylib", RTLD_LAZY);
    if (!hLib) {
        cout << "Failed to load libMathLibrary.dylib: " << dlerror() << endl;
        return 1;
    }
    AddFunc Add = (AddFunc)dlsym(hLib, "Add");
    SubtractFunc Subtract = (SubtractFunc)dlsym(hLib, "Subtract");
    MultiplyFunc Multiply = (MultiplyFunc)dlsym(hLib, "Multiply");
    DivideFunc Divide = (DivideFunc)dlsym(hLib, "Divide");
    ModulusFunc Modulus = (ModulusFunc)dlsym(hLib, "Modulus");
    PowerFunc Power = (PowerFunc)dlsym(hLib, "Power");
    SquareRootFunc SquareRoot = (SquareRootFunc)dlsym(hLib, "SquareRoot");

    if (!Add || !Subtract || !Multiply || !Divide || !Modulus || !Power || !SquareRoot) {
        cout << "Failed to get one or more function addresses: " << dlerror() << endl;
        dlclose(hLib);
        return 1;
    }
    
    Add(5.0, 3.0, Result);
    Subtract(5.0, 3.0, Result);
    Multiply(5.0, 3.0, Result);
    Divide(5.0, 3.0, Result);
    Modulus(5, 3, Result);
    Power(5.0, 3.0, Result);
    SquareRoot(25.0, Result);

    dlclose(hLib);
#endif
    return 0;
}
