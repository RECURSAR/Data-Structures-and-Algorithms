#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<string> sortPeople(vector<string>& names, vector<int>& heights);

int main()
{
    vector<string> names = {"Mary","John","Emma"};
    vector<int> heights = {180,165,170};
    vector<string> result;

    result = sortPeople(names, heights);

    for(int i = 0; i < result.size(); i++)
        cout<<result[i]<<endl;

    return 0;
}

vector<string> sortPeople(vector<string>& names, vector<int>& heights){
    // Vector of pairs to hold the names and heights
    vector<pair<int, string>> people_heights;

    for (int i = 0; i < names.size(); i++)
        people_heights.push_back({heights[i], names[i]});
    
    // Sort pairs based on heights in descending order
    sort(people_heights.begin(), people_heights.end(), [](pair<int, string>& a, pair<int, string>& b) {
        return a.first > b.first;
    });
    
    // Extract the sorted names from the sorted pairs
    vector<string> sortedNames;
    for (auto& person : people_heights)
        sortedNames.push_back(person.second);
    
    return sortedNames;
}