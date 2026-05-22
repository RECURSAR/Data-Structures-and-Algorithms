#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

void runStockSpanner(const vector<string>& commands, const vector<vector<int>>& args);

class StockSpanner {
    stack<pair<int, int>> st;

    public:
        StockSpanner() {
            
        }
        
        int next(int price) {
            int count = 1;

            while(!st.empty()) {
                if(price >= st.top().first) {
                    count += st.top().second;
                    st.pop();
                }
                else
                    break;
            }
            
            st.push({price, count});
            return count;
        }
};

int main() {
    vector<string> commands = {"StockSpanner", "next", "next", "next", "next", "next", "next", "next"};
    vector<vector<int>> args = {{}, {100}, {80}, {60}, {70}, {60}, {75}, {85}};

    runStockSpanner(commands, args);

    return 0;
}

void runStockSpanner(const vector<string>& commands, const vector<vector<int>>& args) {
    StockSpanner* obj = NULL;
    cout << "[";
    for (size_t i = 0; i < commands.size(); ++i) {
        if (commands[i] == "StockSpanner") {
            obj = new StockSpanner();
            cout << "NULL";
        } else if (commands[i] == "next") {
            cout << obj->next(args[i][0]);
        }
        if (i < commands.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]\n";
    delete obj;
}