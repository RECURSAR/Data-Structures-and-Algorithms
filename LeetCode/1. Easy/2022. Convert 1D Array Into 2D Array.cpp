#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
    // Check if it's possible to create the 2D array
        if (original.size() != m * n) 
            return {}; // Return an empty 2D array if impossible
        
        // Initialize the 2D array with m rows and n columns
        vector<vector<int>> result(m, vector<int>(n));

        // Fill the 2D array
        for (int i = 0; i < original.size(); i++) {
            // Calculate the row index and column index for the 2D array
            int row = i / n;
            int col = i % n;
            result[row][col] = original[i];
        }

        return result;
}

int main() {
    vector<int> original = {1, 2, 3, 4};
    int m = 2, n = 2;
    
    vector<vector<int>> result = construct2DArray(original, m, n);
    
    if (result.empty()) {
        cout << "Impossible to construct the 2D array" << endl;
    } else {
        // Print the 2D array
        for (const auto& row : result) {
            for (int elem : row) {
                cout << elem << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}
