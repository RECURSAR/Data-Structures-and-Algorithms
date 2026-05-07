#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int sumSubarrayMins(vector<int>& arr) {
    const int MOD = 1e9 + 7;
    int n = arr.size();
    long long result = 0;

    vector<int> left(n), right(n);
    stack<int> st;

    // Previous Less Element
    for(int i = 0; i < n; i++) {
        while(!st.empty() && arr[st.top()] >= arr[i])
            st.pop();

        left[i] = st.empty() ? i + 1 : i - st.top();
        st.push(i);
    }

    // Clear the stack for the next loop
    while(!st.empty())
        st.pop();

    // Next Less Element
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && arr[st.top()] > arr[i])
            st.pop();
        
        right[i] = st.empty() ? n - i : st.top() - i;
        st.push(i);
    }

    for(int i = 0; i < n; i++)
        result = (result + ((long long)arr[i] * left[i] * right[i]) % MOD) % MOD;

    return (int)result;
}

int main() {
    vector<int> arr = {3, 1, 2, 4};
    
    cout<<sumSubarrayMins(arr)<<endl;

    return 0;
}