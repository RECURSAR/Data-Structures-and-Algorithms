#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<int> findUnion(vector<int> &a, vector<int> &b) {
    vector<int> result;
    size_t p1 = 0, p2 = 0;

    while (p1 < a.size() && p2 < b.size()) {
        if (a[p1] == b[p2]) {
            if (result.empty() || result.back() != a[p1])
                result.push_back(a[p1]);
            
            p1 += 1;
            p2 += 1;
        } else if (a[p1] < b[p2]) {
            if (result.empty() || result.back() != a[p1])
                result.push_back(a[p1]);
            
            p1 += 1;
        } else {
            if (result.empty() || result.back() != b[p2])
                result.push_back(b[p2]);
            
            p2 += 1;
        }
    }

    // b got exhausted and a was still left
    while (p1 < a.size()) {
        if (result.empty() || result.back() != a[p1])
            result.push_back(a[p1]);
        
        p1 += 1;
    }

    // a got exhausted and b was still left
    while (p2 < b.size()) {
        if (result.empty() || result.back() != b[p2])
            result.push_back(b[p2]);
        
        p2 += 1;
    }

    return result;
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5}, b = {1, 2, 3, 6, 7};

    vector<int> result = findUnion(a, b);
    for (auto res : result)
        cout << res << " ";

    return 0;
}