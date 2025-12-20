#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int chalkReplacer(vector<int>& chalk, int k) {
    long long sum = 0;

        // Calculate the total sum of chalk consumption
        for (int j = 0; j < chalk.size(); j++) 
            sum += chalk[j];
        
        // Reduce k by taking modulo with the total sum
        k = k % sum;

        // Find the student who cannot consume the chalk
        for (int i = 0; i < chalk.size(); i++){
            if (k < chalk[i]) 
                return i;

            k = k - chalk[i];
        }

        // This line should ideally never be reached
        return 0; 
}

int main() {
    vector<int> chalk = {5, 1, 5};
    int k = 22;

    int result = chalkReplacer(chalk, k);
    cout << "The student who will replace the chalk is: " << result << endl;

    return 0;
}
