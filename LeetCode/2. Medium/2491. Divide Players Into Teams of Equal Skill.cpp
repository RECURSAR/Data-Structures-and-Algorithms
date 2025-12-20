#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

long long dividePlayers(vector<int>& skill) {
    int n = skill.size();
    
    // Sort the skill array
    sort(skill.begin(), skill.end());
    
    // Calculate the total sum of all skills
    long long totalSum = 0;
    for (int s : skill) {
        totalSum += s;
    }
    
    // Calculate the required team sum
    int numTeams = n / 2;
    long long teamSum = totalSum / numTeams;
    
    // Check if the total sum is divisible by numTeams
    if (totalSum % numTeams != 0) {
        return -1;  // Cannot divide the players into teams with equal sums
    }
    
    long long totalChemistry = 0;
    
    // Try to form teams by pairing smallest and largest
    for (int i = 0; i < numTeams; ++i) {
        int j = n - 1 - i;  // Pair ith smallest with ith largest
        
        // Check if the team sum is correct
        if (skill[i] + skill[j] != teamSum) {
            return -1;  // If not equal, return -1
        }
        
        // Add the chemistry (product of skills) to the total
        totalChemistry += 1LL * skill[i] * skill[j];
    }
    
    return totalChemistry;
}

int main() {
    vector<int> skill = {3, 2, 5, 1, 3, 4}; // Expected output: 22
    cout << "Total chemistry: " << dividePlayers(skill) << endl;

    vector<int> skill2 = {1, 1, 2, 3}; // Expected output: -1 (cannot form equal sum teams)
    cout << "Total chemistry: " << dividePlayers(skill2) << endl;
    
    return 0;
}