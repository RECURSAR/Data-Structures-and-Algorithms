#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
    vector<int> missed;

    // Calculate the current sum of the observed rolls
    int current_sum = accumulate(rolls.begin(), rolls.end(), 0);

    // Calculate the required sum for the missing rolls
    int total_sum = (rolls.size() + n) * mean;
    int required_sum = total_sum - current_sum;

    // Check if the required sum can be distributed to 'n' rolls
    if (required_sum < n || required_sum > 6 * n) 
        return missed;  // Return an empty array if it's impossible

    // Start by giving each roll a value of 1
    missed.assign(n, 1);

    // Distribute the remaining (required_sum - n) across the rolls
    required_sum -= n;  // We've already given 1 to each roll

    for (int i = 0; i < n && required_sum > 0; i++){
        // We can add at most 5 more to each roll (to make it up to 6)
        int add = min(5, required_sum);
        missed[i] += add;
        required_sum -= add;
    }

    return missed;
}

int main()
{
    vector<int> rolls = {3,2,4,3};
    int mean = 4, n = 2;
    
    vector<int> missed = missingRolls(rolls, mean, n);

    for(auto i : missed)
        cout<<i<<endl;

    return 0;
}