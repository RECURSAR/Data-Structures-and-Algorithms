#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    vector<string> words = {"What","must","be","acknowledgment","shall","be"};
    vector<string> current_line, ans;
    int maxWidth = 16, length = 0, i = 0;

    while (i < words.size()) {
        // Check if the current word can be added to the line
        if (length + words[i].size() + current_line.size() <= maxWidth) {
            current_line.push_back(words[i]);
            length += words[i].size();
            i++;
        } else {
            // Distribute spaces for the current line
            int totalSpace = maxWidth - length;
            string line;
            if (current_line.size() == 1) {
                // If only one word, append all extra spaces at the end
                line = current_line[0] + string(totalSpace, ' ');
            } else {
                int spaceBetweenWords = totalSpace / (current_line.size() - 1);
                int extraSpace = totalSpace % (current_line.size() - 1);
                for (int j = 0; j < current_line.size(); j++) {
                    line += current_line[j];
                    if (j < current_line.size() - 1) {
                        line += string(spaceBetweenWords + (j < extraSpace ? 1 : 0), ' ');
                    }
                }
            }
            ans.push_back(line);
            current_line.clear();
            length = 0;
        }
    }

    // Handle the last line separately (left-justified)
    string lastLine = accumulate(current_line.begin(), current_line.end(), string(),
                                 [](const string& a, const string& b) { return a.empty() ? b : a + " " + b; });
    lastLine += string(maxWidth - lastLine.length(), ' ');
    ans.push_back(lastLine);

    // Print the justified text
    for (const auto& line : ans) {
        cout << "\"" << line << "\"" << endl;
    }

    return 0;
}