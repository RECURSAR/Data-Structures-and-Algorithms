#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

string longestDiverseString(int a, int b, int c) {
    priority_queue<pair<int, char>> heap; 

    if(a > 0)
        heap.push({a, 'a'});
    if(b > 0)
        heap.push({b, 'b'});
    if(c > 0)
        heap.push({c, 'c'});

    string result = "";

    while(!heap.empty()){
        auto first = heap.top();
        heap.pop();

        // 2 repeating characters
        if(result.size() >= 2 && result[result.size() - 1] == first.second && result[result.size() - 2] == first.second){
            if(heap.empty())
                break;

            auto second = heap.top();
            heap.pop();

            result += second.second;
            second.first--;

            if(second.first > 0)
                heap.push(second);

            heap.push(first);
        }
        else{
            result += first.second;
            first.first--;
            
            if(first.first > 0) 
                heap.push(first);
        }
    }

    return result;
}

int main() {
    int a = 1, b = 1, c = 7;

    cout<<longestDiverseString(a,b,c);

    return 0;
}