#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    string s = "PAYPALISHIRING";
    int numRows = 4, i = 0, j = 0, jump;
    string res = "";

    if (numRows == 1){
        cout<<s;
        return 0;
    }
    
    for(i=0; i<numRows; i++){
        jump = 2 * (numRows - 1);

        for(j=i; j<s.length(); j+=jump){
            res += s[j];
            if(i>0 && i<numRows-1 && j + jump - 2 * i < s.length())
                res += s[j + jump - 2 * i];
        }
    }

    cout<<res<<endl;

    return 0;
}