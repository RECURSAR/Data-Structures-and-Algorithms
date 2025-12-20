#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void print_divisors(int n) {
    vector<int> larger_divisors;

    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            cout << i << " ";
            // If 36 / 4 is 0 then we are printing it and storing 9 (36 / 4) in larger_divisors
            if(i != n / i) 
                larger_divisors.push_back(n / i); 
        }
    }

    reverse(larger_divisors.begin(), larger_divisors.end());

    for(int divisor : larger_divisors)
        cout << divisor << " ";
}

int main() {
    int n = 20;

    print_divisors(n);

    return 0;
}