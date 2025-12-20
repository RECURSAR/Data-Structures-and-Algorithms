#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    string haystack = "HOMELANDER", needle = "LAND";
    int i=0, flag=0;

    while(i<haystack.length())
    {
        if(haystack[i] == needle[0])
        {
            int j=0;
            while(j<needle.length())
            {
                if(haystack[i+j] != needle[j])
                {
                    break;
                }
                j++;
            }
            
            if(j == needle.length())
            {
                cout<<i;
                flag = 1;
                break;
            }
        }
        i++;
    }

    if (flag == 0){
        cout<<-1;
    }

    return 0;
}