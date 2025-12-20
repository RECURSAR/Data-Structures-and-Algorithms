#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
 
using namespace std;
 
int main()
{
    vector<int> citations = {3,0,6,1,5};
    int h_index = 0;

    sort(citations.begin(), citations.end(), greater<int>());

    for(int i=0; i<citations.size();i++){
        if (citations[i] >= i + 1) 
            h_index = i + 1;
        else 
            break;
    }

    cout<<h_index;
    
    return 0;
}