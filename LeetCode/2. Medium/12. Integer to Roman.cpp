#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int main()
{
    map<int, string> roman_map;

    roman_map[1] = "I";
    roman_map[4] = "IV";
    roman_map[5] = "V";
    roman_map[9] = "IX";
    roman_map[10] = "X";
    roman_map[40] = "XL";
    roman_map[50] = "L";
    roman_map[90] = "XC";
    roman_map[100] = "C";
    roman_map[400] = "CD";
    roman_map[500] = "D";
    roman_map[900] = "CM";
    roman_map[1000] = "M";
    
    string res = "";
    int num = 1994, count = 0;
    map<int, string> :: reverse_iterator ptr; 

    for(ptr=roman_map.rbegin(); ptr!=roman_map.rend(); ptr++){
        if(num / ((*ptr).first)){
            count = num / (*ptr).first;

            for(int i=0; i<count; i++)
                res.append((*ptr).second);

            num = num % (*ptr).first;
        }
    }

    cout<<res;
    
    return 0;
}
