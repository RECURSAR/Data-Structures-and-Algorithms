#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};
    vector<int> result;

    if (words.empty() || s.empty())
    {
        for (int i = 0; i < result.size(); i++)
            cout << result[i];  
    }

    int word_len = words[0].size();
    int num_words = words.size();
    int total_len = word_len * num_words;

    if (s.size() < total_len)
    {
        for (int i = 0; i < result.size(); i++)
            cout << result[i]; 
    }

    unordered_map<string, int> word_count;

    for (const string &word : words)
        word_count[word]++;
    
    for (int i = 0; i < word_len; ++i)
    {
        int left = i;
        int right = i;
        int count = 0;

        unordered_map<string, int> current_count;

        while (right + word_len <= s.size())
        {
            string word = s.substr(right, word_len);
            right += word_len;

            // word is found in the map
            if (word_count.find(word) != word_count.end())
            {
                current_count[word]++;
                count++;

                while (current_count[word] > word_count[word])
                {
                    // substr(index, length)    copies from index till the size i.e length 
                    string left_word = s.substr(left, word_len);
                    current_count[left_word]--;
                    count--;
                    left += word_len;
                }

                if (count == num_words)
                    result.push_back(left);
                
            }

            else
            {
                current_count.clear();
                count = 0;
                left = right;
            }
        }
    }

    for (int i = 0; i < result.size(); i++)
        cout << result[i];
    
}