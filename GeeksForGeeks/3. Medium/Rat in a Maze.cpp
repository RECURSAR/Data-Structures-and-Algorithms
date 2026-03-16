#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

void findPath(int row, int column, string path, vector<string> &result, vector<vector<int>> &maze) {
    if(row < 0 || column < 0 || row >= (int)maze.size() || column >= (int)maze[0].size() || maze[row][column] == 0)
        return;

    if(row == (int)maze.size() - 1 && column == (int)maze[0].size() - 1) {
        result.push_back(path);
        return;
    }
    
    // Mark as visited
    maze[row][column] = 0;

    findPath(row + 1, column, path + "D", result, maze);
    findPath(row - 1, column, path + "U", result, maze);
    findPath(row, column + 1, path + "R", result, maze);
    findPath(row, column - 1, path + "L", result, maze);

    // Backtrack
    maze[row][column] = 1;
}

vector<string> ratInMaze(vector<vector<int>>& maze) {
    vector<string> result;

    findPath(0, 0, "", result, maze);
    sort(result.begin(), result.end());

    return result;
}

int main() {
    vector<vector<int>> maze = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    
    vector<string> result = ratInMaze(maze);
    for(auto res : result)
        cout<<res<<" ";

    return 0;
}