#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

string compressedString(string word) {
    int count = 1;
    string comp = "";

    for (int i = 0; i < word.size(); i++) {
        if (i < word.size() && word[i] == word[i + 1]) {
            count += 1;

            if (count == 9) {
                comp += to_string(count);
                comp += word[i];
                count = 1;
                i++;
            }
        } else {
            comp += to_string(count);
            comp += word[i];
            count = 1;
        }
    }

    return comp;
}

int main() {
    string word = "abcde";

    cout<<compressedString(word);

    return 0;
}