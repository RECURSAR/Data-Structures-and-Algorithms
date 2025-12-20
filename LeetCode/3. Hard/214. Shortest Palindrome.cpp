#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

// Bruteforce Approach
/*
bool isPalindrome(const std::string& str) {
    int left = 0;
    int right = str.size() - 1;

    while (left < right) {
        if (str[left] != str[right])
            return false;
        
        left++;
        right--;
    }

    return true;
}

string shortestPalindrome(string s) {
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
    
    // Iterate through each possible suffix of s
    for (int i = 0; i <= s.size(); i++) {
        if (isPalindrome(s.substr(0, s.size() - i)))
            // Form the shortest palindrome by adding the necessary characters from rev_s
            return rev_s.substr(0, i) + s;  
    }

    return "";
}
*/

// Optimal Approach - Rabin-Karp
const int MOD = 1e9 + 7;  // A large prime number for the hash modulus
const int BASE = 29;      // Base for the polynomial hash

string shortestPalindrome(string s) {
    int n = s.size();
    if (n == 0) return "";

    // Initialize hash values
    long long hash1 = 0, hash2 = 0;
    long long base_pow = 1;  // BASE^i mod MOD
    int palindrome_len = 0;

    // Traverse the string and compute the hash for the prefix and reverse prefix
    for (int i = 0; i < n; ++i) {
        // Hash1 is the forward hash for the first i+1 characters of s
        hash1 = (hash1 * BASE + (s[i] - 'a' + 1)) % MOD;

        // Hash2 is the reverse hash for the first i+1 characters of s
        hash2 = (hash2 + (s[i] - 'a' + 1) * base_pow) % MOD;

        // Update the base power
        base_pow = (base_pow * BASE) % MOD;

        // If the two hashes are equal, then the prefix s[0...i] is a palindrome
        if (hash1 == hash2) {
            palindrome_len = i + 1;
        }
    }

    // The part of the string that needs to be added is the suffix after the longest palindrome prefix
    string to_add = s.substr(palindrome_len);

    // Reverse the part to add and prepend it to the original string to make it a palindrome
    reverse(to_add.begin(), to_add.end());
    
    return to_add + s;
}

int main() {
    string s = "aditya";

    cout<<shortestPalindrome(s);

    return 0;
}