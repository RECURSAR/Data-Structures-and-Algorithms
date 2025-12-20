#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

char getMinChar(const vector<int>& count) {
    for (int i = 0; i < 26; ++i)
        if (count[i])
            return 'a' + i;

    return 'a';
}

string robotWithString(string s) {
    string ans;
    vector<int> count(26);
    stack<char> stack;

    for (const char c : s)
      ++count[c - 'a'];

    for (const char c : s) {
      stack.push(c);
      --count[c - 'a'];
      const char minChar = getMinChar(count);
      
      while (!stack.empty() && stack.top() <= minChar)
        ans += stack.top(), stack.pop();
    }

    while (!stack.empty())
      ans += stack.top(), stack.pop();

    return ans;
}

int main() {
    string s = "zza";
    
    cout<<robotWithString(s);

    return 0;
}