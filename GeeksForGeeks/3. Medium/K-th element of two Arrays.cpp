#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int kthElement(vector<int> &a, vector<int> &b, int k) {
    if(a.size() > b.size())
        return kthElement(b, a, k);

    size_t n1 = a.size(), n2 = b.size();
    int low = max(0, k - (int)n2), high = min(k, (int)n1), left1 = 0, left2 = 0, right1 = 0, right2 = 0, cut1 = 0, cut2 = 0;

    while(low <= high) {
        cut1 = low + (high - low) / 2;
        cut2 = k - cut1;

        left1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
        left2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1];
        right1 = (cut1 == (int)n1) ? INT_MAX : a[cut1];
        right2 = (cut2 == (int)n2) ? INT_MAX : b[cut2];

        // Mid-Point Found
        if(left1 <= right2 && left2 <= right1)
            return max(left1, left2);
        else if(left1 > right2)
            high = cut1 - 1;
        else
            low = cut1 + 1;
    }

    return -1;
}

int main() {
    vector<int> a = {2, 3, 6, 7, 9}, b = {1, 4, 8, 10};
    int k = 5;

    cout<<kthElement(a, b, k);

    return 0;
}