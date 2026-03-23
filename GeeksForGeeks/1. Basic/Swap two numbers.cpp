#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

pair<int, int> get(int a, int b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    return {a, b};
}

int main() {
    int a = 13, b = 9;
    
    pair<int, int> result = get(a, b);
    cout<<result.first<<" "<<result.second;

    return 0;
}