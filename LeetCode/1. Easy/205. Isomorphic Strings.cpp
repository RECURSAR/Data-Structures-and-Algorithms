#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
   string s = "foo", t = "bar";
   map<char, char> m1, m2;
   char temp1, temp2;
   bool result;

   for(int i = 0; i<s.size(); i++){
        temp1 = s[i];
        temp2 = t[i];

        // Both strings should be isomorphic to eachother
        if(m1.find(temp1) != m1.end() && m1[temp1] != temp2 || m2.find(temp2) != m2.end() && m2[temp2] != temp1){
            result = false;
            cout<<result<<endl;
            exit(0);
        }

        m1[temp1] = temp2;
        m2[temp2] = temp1;
   }

    result = true;
    cout<<result;

   return 0;
}