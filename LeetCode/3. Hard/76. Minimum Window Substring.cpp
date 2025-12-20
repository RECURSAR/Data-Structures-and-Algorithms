#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s = "ADOBECODEBANC", t = "ABC", answer;
    int length = INT_MAX, left = 0, right = 0, have = 0, need, result_length = INT_MAX;
    int result[2] = {-1, -1};
    char temp;

    if (t.empty()){
        cout<<"Empty String"<<endl;
        exit(0);
    }

    unordered_map<char, int> countT, window;

    for (int i = 0; i < t.size(); i++)
        countT[t[i]]++;

    need = countT.size();

    for(right = 0; right<s.size(); right++){
        temp = s[right];
        window[temp]++;

        // Element should be in countT and count should be same in both window
        if(countT.find(temp) != countT.end() && window[temp] == countT[temp])
            have++;

        while(have == need){
            // Update Result
            if((right - left + 1) < result_length){
                result[0] = left;
                result[1] = right;
                result_length = right - left + 1;
            }
            // Remove elements from left after need is satisfied to minimize the window size
            window[s[left]]--;

            if(countT.find(s[left]) != countT.end() && window[s[left]] < countT[s[left]])
                have--;
            
            left++;
        }
    }

   if (result[0] != -1) { // Check if a result was found
        answer = s.substr(result[0], result_length);
        cout << answer << endl;
    } 
    else{
        cout << "No valid window found" << endl;
        exit(0);
    }
        
    return 0;
}