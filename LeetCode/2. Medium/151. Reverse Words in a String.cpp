#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    string s = "  Bob    Loves  Alice   ";
    stack<string> st;
    string word = "";

    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == ' ')
        {
            if(word != "")
            {
                st.push(word);
                word = "";
            }
        }
        else
        {
            word += s[i];
        }
    }

    if(word != "")
        st.push(word);

    string ans = "";

    while(!st.empty())
    {
        ans += st.top();
        st.pop();
        if(!st.empty())
        {
            ans += " ";
        }
    }
    
    cout<<ans;    
    return 0;
}