#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
    vector<string> s = {"flower","flow","flight"}; 
    string res = "";

    if(s.size() == 0) {
        cout<<res;
        return 0;
    }

    for(int i=0; i<s[0].size(); i++) {
        char c = s[0][i];
        for(int j=1; j<s.size(); j++) {
            if(i >= s[j].size() || s[j][i] != c) {
                cout<<res;
                return 0;
            }
        }
        res += c;
    }

    cout<<res;
    
    return 0;
}