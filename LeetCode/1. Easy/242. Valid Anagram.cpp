#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s = "rat", t = "car";
    map<char, int> m1, m2;
    bool result;

     if (s.size() != t.size()){
        result = false;
        cout<<result<<endl;
        exit(0);
     }
            
    for (int i = 0; i < s.size(); i++){
        m1[s[i]]++;
        m2[t[i]]++;
    }
        
    for (int i = 0; i < t.size(); i++){
        if(m1.find(t[i]) != m1.end() && m1[t[i]] == m2[t[i]])
            result = true;

        else{
            result = false;
            cout<<result<<endl;
            exit(0);
        }    
    }

cout << result << endl;

return 0;
}
