#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
   string ransomNote="aa", magazine="aab";
   map<char, int> ransom, mag;
   char temp;
   bool result;
   

   for(int i = 0; i < magazine.size(); i++)
        mag[magazine[i]]++;
   
    for(int i = 0; i < ransomNote.size(); i++){
        temp = ransomNote[i];
        ransom[temp]++;

        if(mag.find(temp) != mag.end() && mag[temp] >= ransom[temp])
            result = true;
        
        else{
            result = false;
            break;
        }
    }

    cout<<result<<endl;

   return 0;
}