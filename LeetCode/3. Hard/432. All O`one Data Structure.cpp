#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

class AllOne {
private:
    struct Bucket {
        int count;
        unordered_set<string> keys;
        Bucket(int c) : count(c) {}
    };
    
    unordered_map<string, list<Bucket>::iterator> keyCountMap; // Maps key -> bucket
    unordered_map<int, list<Bucket>::iterator> countBucketMap; // Maps count -> bucket
    list<Bucket> bucketList; // Doubly linked list of buckets

public:
    /** Initialize your data structure here. */
    AllOne() {}

    /** Increment the count of the key by 1. */
    void inc(string key) {
        if (keyCountMap.find(key) == keyCountMap.end()) {
            // New key, start with count 1
            if (bucketList.empty() || bucketList.front().count != 1) {
                bucketList.push_front(Bucket(1));
            }
            bucketList.front().keys.insert(key);
            keyCountMap[key] = bucketList.begin();
            countBucketMap[1] = bucketList.begin();
        } else {
            // Increment existing key
            auto currentBucket = keyCountMap[key];
            int newCount = currentBucket->count + 1;

            // Remove key from current bucket
            currentBucket->keys.erase(key);

            // Check if there's already a bucket for the new count
            auto nextBucket = next(currentBucket);
            if (nextBucket == bucketList.end() || nextBucket->count != newCount) {
                nextBucket = bucketList.insert(nextBucket, Bucket(newCount));
            }
            nextBucket->keys.insert(key);

            // Update maps
            keyCountMap[key] = nextBucket;
            countBucketMap[newCount] = nextBucket;

            // Remove current bucket if it is empty
            if (currentBucket->keys.empty()) {
                countBucketMap.erase(currentBucket->count);
                bucketList.erase(currentBucket);
            }
        }
    }

    /** Decrement the count of the key by 1. */
    void dec(string key) {
        if (keyCountMap.find(key) == keyCountMap.end()) {
            return; // Key doesn't exist
        }
        
        auto currentBucket = keyCountMap[key];
        int newCount = currentBucket->count - 1;

        // Remove key from current bucket
        currentBucket->keys.erase(key);

        if (newCount > 0) {
            // Check if there's already a bucket for the new count
            auto prevBucket = prev(currentBucket);
            if (currentBucket == bucketList.begin() || prevBucket->count != newCount) {
                prevBucket = bucketList.insert(currentBucket, Bucket(newCount));
            }
            prevBucket->keys.insert(key);
            keyCountMap[key] = prevBucket;
            countBucketMap[newCount] = prevBucket;
        } else {
            // If count becomes zero, remove the key entirely
            keyCountMap.erase(key);
        }

        // Remove current bucket if it is empty
        if (currentBucket->keys.empty()) {
            countBucketMap.erase(currentBucket->count);
            bucketList.erase(currentBucket);
        }
    }

    /** Returns one of the keys with the maximal count. */
    string getMaxKey() {
        if (bucketList.empty()) {
            return "";
        }
        return *(bucketList.back().keys.begin());
    }

    /** Returns one of the keys with the minimal count. */
    string getMinKey() {
        if (bucketList.empty()) {
            return "";
        }
        return *(bucketList.front().keys.begin());
    }
};

int main() {
    // Basic operations
    AllOne allOne;
    allOne.inc("key1");
    allOne.inc("key1");
    allOne.dec("key1");
    allOne.inc("key2");
    allOne.inc("key3");
    allOne.dec("key2");

    // Edge cases
    allOne.dec("key4"); // Non-existent key
    allOne.inc("key5");
    allOne.inc("key6");
    allOne.inc("key7");
    allOne.dec("key5");
    allOne.dec("key5"); // Decrement to zero

    // Performance
    const int numKeys = 1000000;
    vector<string> keys(numKeys);
    generate(keys.begin(), keys.end(), [&]() { return "key" + to_string(rand()); });

    auto startTime = chrono::high_resolution_clock::now();
    for (const string& key : keys) {
        allOne.inc(key);
        allOne.dec(key);
    }
    auto endTime = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = endTime - startTime;

    // Output results
    cout << "Performance test:\n";
    cout << "  - Number of keys: " << numKeys << "\n";
    cout << "  - Time taken: " << duration.count() << " seconds\n";
    cout << "  - Average time per operation: " << duration.count() / (numKeys * 2) << " seconds\n";

    // Corner cases
    allOne.inc("key8");
    allOne.inc("key9");
    allOne.dec("key8");
    allOne.inc("key10");
    allOne.dec("key10");
    allOne.dec("key10"); // Decrement to zero

    // Output results
    cout << "\nCorner case test:\n";
    cout << "  - Max key: " << allOne.getMaxKey() << "\n";
    cout << "  - Min key: " << allOne.getMinKey() << "\n";

    return 0;
}