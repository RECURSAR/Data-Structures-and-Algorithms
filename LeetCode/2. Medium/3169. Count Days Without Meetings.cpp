#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int countDays(int days, vector<vector<int>>& meetings) {
    int freeDays = 0;
    int prevEnd = 0;

    sort(meetings.begin(), meetings.end());

    for (const vector<int>& meeting : meetings) {
      const int start = meeting[0];
      const int end = meeting[1];
      if (start > prevEnd)
        freeDays += start - prevEnd - 1;
      prevEnd = max(prevEnd, end);
    }

    return freeDays + max(0, days - prevEnd);
}

int main() {
    int days = 10;
    vector<vector<int>> meetings = {{5,7},{1,3},{9,10}};

    cout<<countDays(days, meetings);

    return 0;
}