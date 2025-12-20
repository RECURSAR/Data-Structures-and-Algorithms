#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    int x = 0, y = 0;

    // Directions: North, East, South, West
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int index = 0; // Start facing North
    int max_distance = 0;

    // Use a set to store obstacles as pairs of coordinates
    set<pair<int, int>> obstacles_set;

    for (const auto& obstacle : obstacles)
        obstacles_set.insert({obstacle[0], obstacle[1]});
    
    for (int command : commands){
        // Turn right
        if(command == -1) 
            index = (index + 1) % 4;

        // Turn left
        else if(command == -2) 
            index = (index - 1) % 4; // Equivalent to (index - 1 + 4) % 4
        
        else{
            for(int step = 0; step < command; step++){
                int nx = x + directions[index][0];
                int ny = y + directions[index][1];

                // Check if the next position is an obstacle
                if (obstacles_set.find({nx, ny}) != obstacles_set.end()) 
                    break; // Stop moving in this direction if there's an obstacle  

                // Update position
                x = nx;
                y = ny;
                max_distance = max(max_distance, x * x + y * y);
            }
        }
    }

    return max_distance;
}

int main() {
    vector<int> commands = {4, -1, 4, -2, 4};
    vector<vector<int>> obstacles = {{2, 4}};
    int max_distance = robotSim(commands, obstacles);

    cout << max_distance << endl;
    return 0;
}
