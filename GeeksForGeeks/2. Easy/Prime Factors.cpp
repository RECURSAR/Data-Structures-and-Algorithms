#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<int> primeFac(int n) {
    vector<int> result;

    if((n & 1) == 0) {
        result.push_back(2);

        while((n & 1) == 0)
            n >>= 1;
    }

    for(int i = 3; i <= sqrt(n); i += 2) {
        if(n % i == 0) {
            result.push_back(i);

            while(n % i == 0)
                n = n / i;
        }
    }

    if(n > 1)
        result.push_back(n);

    return result;
}

int main() {
    int n = 100;
    
    vector<int> result = primeFac(n);
    for(auto res : result)
        cout<<res<<" ";

    return 0;
}