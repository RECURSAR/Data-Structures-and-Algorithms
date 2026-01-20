#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

// Using Maths (Optimal Way - 1)
/*
vector<int> findTwoElement(vector<int>& arr) {
    int repeatingNumber = 0, missingNumber = 0;
    long long val1 = 0, val2 = 0;
    long long SN = (arr.size() * (arr.size() + 1)) / 2;
    long long S2N = (arr.size() * (arr.size() + 1) * (2 * arr.size() + 1)) / 6;
    long long S = 0, S2 = 0;

    for(size_t i = 0; i < arr.size(); i++) {
        S += arr[i];
        S2 += (long long)arr[i] * (long long)arr[i];
    }

    val1 = S - SN;          // (X - Y)
    val2 = S2 - S2N;        // (X^2 - Y^2) -> (X + Y)(X - Y)
    val2 = val2 / val1;     // (X + Y)

    repeatingNumber = (val1 + val2) / 2;
    missingNumber = repeatingNumber - val1;

    return {(int)repeatingNumber, (int)missingNumber};
}*/

// Using XOR (Optimal Way - 2)
vector<int> findTwoElement(vector<int>& arr) {
    int XOR = 0, bitNumber = 0, zero = 0, one = 0, count = 0;

    // (a0, a1, a2 ... an) ^ (1, 2, 3 ... n)
    for(size_t i = 0; i < arr.size(); i++) {
        // XOR of all elements in nums
        XOR = XOR ^ arr[i];

        // XOR of all numbers from 1 to n
        XOR = XOR ^ (i + 1);
    }

    // Finding the set bit using AND
    bitNumber = (XOR & ~(XOR - 1));

    // Populating one and zero club by iterating over array elements
    for(size_t i = 0; i < arr.size(); i++) {
        // Part of the 1 club
        if((arr[i] & bitNumber) != 0)
            one = one ^ arr[i];
        // Part of the 0 club
        else
            zero = zero ^ arr[i];
    }

    // Populating one and zero club by iterating over natural numbers
    for(size_t i = 1; i <= arr.size(); i++) {
        // Part of the 1 club
        if((i & bitNumber) != 0)
            one = one ^ i;
        // Part of the 0 club
        else
            zero = zero ^ i;
    }

    // Occurence count of zero
    for(size_t i = 0; i < arr.size(); i++) {
        if(arr[i] == zero)
            count += 1;
    }

    // Zero is repeating number and One is missing number
    if(count == 2)
        return {zero, one};
    
    // One is repeating number and Zero is missing number
    return {one, zero};
}

int main() {
    vector<int> arr = {2, 2};

    vector<int> result = findTwoElement(arr);
    for(auto num : result)
      cout<<num<<" ";

    return 0;
}