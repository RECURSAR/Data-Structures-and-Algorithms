#include <iostream>

using namespace std; 

double pow(double x, int n) {
    // Base case
    if (n == 0)
        return 1.0;

    // Calculate power for n // 2
    double half = pow(x, n / 2);

    // If n is even, the result is half * half
    if (n % 2 == 0)
        return half * half;
    else {
        // If n is odd, and n > 0, the result is x * half * half
        if (n > 0)
            return x * half * half;
        else
            // If n < 0, the result is (1/x) * half * half
            return (half * half) / x;
    }
}

int main() {
    double x = 2.0;
    int n = 10;
    cout << "pow(" << x << ", " << n << ") = " << pow(x, n) << std::endl;
    return 0;
}
