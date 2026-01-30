#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

long long hoursConsumed(const vector<int> &piles, int k) {
    long long hoursConsumed = 0;

    for(int pile : piles)
        // Upper Bound needs to be taken because if a pile takes even 2.3 hours it will take 3 hours for consumption
        hoursConsumed += ceil((double)pile / k);

    return hoursConsumed;
}

int minEatingSpeed(vector<int>& piles, int h) {
    long long low = 1, mid = 0, high = *max_element(piles.begin(), piles.end()), totalHours = 0;
    int k = 0;

    while(low <= high) {
        mid = low + (high - low) / 2;
        totalHours = hoursConsumed(piles, mid);

        if(totalHours <= h) {
            k = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return k;
}

int main() {
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    cout<<minEatingSpeed(piles, h);

    return 0;
}