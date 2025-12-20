#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
int sum_of_digits(int n);

int main()
{
    int n = 2, sum = 0, temp;
    map<int, int> number;
    bool result;

    sum = sum_of_digits(n);
    number[n] = sum;

    while(sum != 1){
        temp = sum;
        if(number.find(temp) != number.end()){
            result = false;
            cout<<result<<endl;
            exit(0);
        }
        sum = sum_of_digits(sum);
        number[temp] = sum;
    }

    result = true;
    cout<<result<<endl;
    
    return 0;
}

int sum_of_digits(int n){
    int result = 0, new_num, temp;
    new_num = n;

    while(new_num != 0){
        temp = new_num % 10;
        result = result + temp * temp;
        new_num = new_num / 10;
    }

    return result;
}