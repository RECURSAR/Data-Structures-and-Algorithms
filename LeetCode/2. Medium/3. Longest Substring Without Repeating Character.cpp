#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
   string s = "pwwkew";
   set<char> CharSet;       // Ordered Set is used (Only unique elements are stored in the set in ascending order)
   int length = 0, l = 0;
   
   for(int r = 0; r < s.size(); r++){
        // find method returns an iterator to  the element found,
        // If the find method returns an iterator to the end of the set, it means the element is not found.
        
        // Checking if the element is in the set
        while(CharSet.find(s[r]) != CharSet.end()){
            CharSet.erase(s[l]);
            l++;
            }

        CharSet.insert(s[r]);
        length = max(length, r - l + 1);
    }

   cout<<length; 
   return 0;
}