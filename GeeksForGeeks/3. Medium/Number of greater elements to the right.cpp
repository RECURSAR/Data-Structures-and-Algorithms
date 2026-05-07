#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

class BIT {
    private:
        int n;
        vector<int> bit;
        
    public:
        BIT(int size) : n(size), bit(size + 1, 0) {}

        void update(int i) {
            while(i <= n) {
                bit[i] += 1;
                i += i & (-i);
            }
        }

        int query(int i) {
            int total = 0;
            while(i > 0) {
                total += bit[i];
                i -= i & (-i);
            }

            return total;
        }

        int count_greater(int i) {
            return query(n) - query(i);
        }
};

vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
    int n = arr.size();
    
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());
    sortedArr.erase(unique(sortedArr.begin(), sortedArr.end()), sortedArr.end());

    int m = sortedArr.size();

    auto getRank = [&](int val) {
        return (int)(lower_bound(sortedArr.begin(), sortedArr.end(), val) - sortedArr.begin()) + 1;
    };

    unordered_map<int, vector<int>> queryMap;
    for(int i = 0; i < (int)indices.size(); i++)
        queryMap[indices[i]].push_back(i);

    BIT bit(m);
    vector<int> result(indices.size());

    for(int i = n - 1; i >= 0; i--) {
        if(queryMap.count(i)) {
            int ans = bit.count_greater(getRank(arr[i]));
            for(int slot : queryMap[i])
                result[slot] = ans;
        }

        bit.update(getRank(arr[i]));
    }

    return result;
}

int main() {
    vector<int> arr = {3, 4, 2, 7, 5, 8, 10, 6}, indices = {0, 5};

    vector<int> result = count_NGE(arr, indices);
    for(auto res : result)
        cout<<res<<" ";

    return 0;
}