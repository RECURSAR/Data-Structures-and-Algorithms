#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
    // Sort the input array
    sort(arr.begin(), arr.end());

    // Initialize an array to store occurrences
    vector<int> occurrences;
    int count = 1;

    // Iterate through the sorted array to count occurrences
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] == arr[i - 1]) {
            count++;
        } else {
            occurrences.push_back(count);
            count = 1;
        }
    }

    // Add the count of the last element
    occurrences.push_back(count); 

    // Check for uniqueness in the occurrences array
    sort(occurrences.begin(), occurrences.end());
    for (int i = 1; i < occurrences.size(); i++) {
        if (occurrences[i] == occurrences[i - 1]) {
            return false; // Not unique
        }
    }
    
    return true; // Unique occurrences
}

int main() {
    vector<int> arr = {3, 1, 2, 2, 1, 3, 3, 3};
    if (uniqueOccurrences(arr)) {
        cout << "Occurrences are unique" << endl;
    } else {
        cout << "Occurrences are not unique" << endl;
    }
    return 0;
}
