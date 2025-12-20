#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    string pattern = "abba", s = "dog cat cat dog", w;
    char c;
    map<char, string> charToWord;
    map<string, char> WordTochar;
    int j = 0;
    bool result = true;

    // The istringstream stream allows you to extract words 
    // from the string s easily without having to manually handle spaces and end-of-string conditions.

    istringstream stream(s);

    for (int i = 0; i < pattern.size(); i++) {
        c = pattern[i];

        // stream >> w attempts to read the next whitespace-separated word from the input stream stream and stores it in the variable w.
        if (!(stream >> w)) {
            result = false;
            break;
        }

        if (charToWord.find(c) != charToWord.end() && charToWord[c] != w) {
            result = false;
            break;
        }

        if (WordTochar.find(w) != WordTochar.end() && WordTochar[w] != c) {
            result = false;
            break;
        }

        charToWord[c] = w;
        WordTochar[w] = c;
    }

    // If there are more words left in the string, the pattern does not match
    if (stream >> w) {
        result = false;
    }

    cout << result << endl;

    return 0;
}
