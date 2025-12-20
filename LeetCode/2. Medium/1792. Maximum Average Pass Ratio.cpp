#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

// Returns the extra pass ratio if a brilliant student joins.
double extraPassRatio(int pass, int total) {
    return (pass + 1) / static_cast<double>(total + 1) - pass / static_cast<double>(total);
}

double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
    // (extra pass ratio, pass, total)
    priority_queue<tuple<double, int, int>> maxHeap;

    for (const vector<int>& c : classes) {
        const int pass = c[0];
        const int total = c[1];
        maxHeap.emplace(extraPassRatio(pass, total), pass, total);
    }

    for (int i = 0; i < extraStudents; ++i) {
        const auto top = maxHeap.top();
        const double _ = std::get<0>(top);
        const int pass = std::get<1>(top);
        const int total = std::get<2>(top);
        maxHeap.pop();
        maxHeap.emplace(extraPassRatio(pass + 1, total + 1), pass + 1, total + 1);
    }

    double ratioSum = 0;

    while (!maxHeap.empty()) {
        double _;
        int pass, total;
        std::tie(_, pass, total) = maxHeap.top();
        maxHeap.pop();
        ratioSum += pass / static_cast<double>(total);
    }

    return ratioSum / classes.size();
}

int main() {
    vector<vector<int>> classes = {{1,2}, {3,5}, {2,2}};
    int extraStudents = 2;

    cout<<maxAverageRatio(classes, extraStudents);

    return 0;
}