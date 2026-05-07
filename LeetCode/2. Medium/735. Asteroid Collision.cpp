#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> result;
    stack<int> st;

    for(int asteroid : asteroids) {
        bool alive = true;

        while(alive && asteroid < 0 && !st.empty() && st.top() > 0) {
            int top = st.top();

            if(top < abs(asteroid))
                st.pop();
            else if(top == abs(asteroid)) {
                st.pop();
                alive = false;
            }
            else
                alive = false;
        }

        if(alive)
            st.push(asteroid);
    }

    while(!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    vector<int> asteroids = {5, 10, -5};
    
    vector<int> result = asteroidCollision(asteroids);
    for(auto res : result)
        cout<<res<<" ";

    return 0;
}