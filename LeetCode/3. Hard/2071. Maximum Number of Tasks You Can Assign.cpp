#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
    int ans = 0;
    int l = 0;
    int r = min(tasks.size(), workers.size());

    std::sort(tasks.begin(), tasks.end());
    std::sort(workers.begin(), workers.end());

    // Returns true if we can finish k tasks.
    auto canComplete = [&](int k, int pillsLeft) {
      // k strongest workers
      map<int, int> sortedWorkers;
      for (int i = workers.size() - k; i < workers.size(); ++i)
        ++sortedWorkers[workers[i]];

      // Out of the k smallest tasks, start from the biggest one.
      for (int i = k - 1; i >= 0; --i) {
        // Find the first worker that has strength >= tasks[i].
        auto it = sortedWorkers.lower_bound(tasks[i]);
        if (it != sortedWorkers.end()) {
          if (--(it->second) == 0)
            sortedWorkers.erase(it);
        } else if (pillsLeft > 0) {
          // Find the first worker that has strength >= tasks[i] - strength.
          it = sortedWorkers.lower_bound(tasks[i] - strength);
          if (it != sortedWorkers.end()) {
            if (--(it->second) == 0)
              sortedWorkers.erase(it);
            --pillsLeft;
          } else {
            return false;
          }
        } else {
          return false;
        }
      }

      return true;
    };

    while (l <= r) {
      const int m = (l + r) / 2;
      if (canComplete(m, pills)) {
        ans = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }

    return ans; 
}

int main() {
    vector<int> tasks = {3,2,1}, workers = {0,3,3};
    int pills = 1, strength = 1;
    
    cout<<maxTaskAssign(tasks, workers, pills, strength);

    return 0;
}