#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<int> nextSmallerEle(vector<int>& arr) {
    vector<int> result(arr.size(), -1);
    stack<int> st;

    for(int i = arr.size() - 1; i >= 0; i--) {
        while(!st.empty() && arr[i] <= st.top())
            st.pop();

        result[i] = st.empty() ? -1 : st.top();

        st.push(arr[i]);
    }

    return result;
}

int main() {
    vector<int> arr = {4, 8, 5, 2, 25};

    vector<int> result = nextSmallerEle(arr);
    for(auto res : result)
        cout<<res<<" ";

    return 0;
}