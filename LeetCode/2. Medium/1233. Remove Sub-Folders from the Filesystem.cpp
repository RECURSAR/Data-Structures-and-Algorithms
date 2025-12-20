#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<string> removeSubfolders(vector<string>& folder) {
    sort(folder.begin(), folder.end());
    vector<string> result;

    for(auto f : folder){
        if(result.empty() || f.compare(0, result.back().size(), result.back()) != 0 || f[result.back().size()] != '/')
            result.push_back(f);
    }

    return result;
}

int main()
{
    vector<string> folder = {"/a","/a/b","/c/d","/c/d/e","/c/f"};

    vector<string> result = removeSubfolders(folder);
    for(auto it : result)
        cout<<it<<" ";

    return 0;
}