#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

string largestNumber(vector<int>& nums) {
    vector<string> numStrings;
    for (int num : nums)
        numStrings.push_back(to_string(num));
    
    // Custom comparator: compare concatenated strings (a+b) and (b+a)
    sort(numStrings.begin(), numStrings.end(), [](string &a, string &b) {
        return a + b > b + a;
    });
    
    // If the largest number is "0", return "0"
    if (numStrings[0] == "0")
        return "0";
    
    // Concatenate all the strings to form the largest number
    string result = "";
    for (string &numStr : numStrings)
        result += numStr;
    
    return result;
}

int main() {
    vector<int> nums = {3,30,34,5,9};

    cout<<largestNumber(nums); 

    return 0;
}