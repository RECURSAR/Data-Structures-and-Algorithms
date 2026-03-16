#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool traverse(int index, int currentRow, int currentColumn, vector<vector<char>> &board, string word) {
    if(index == (int)word.size())
        return true;

    if(currentRow < 0 || currentColumn < 0 || currentRow >= (int)board.size() || currentColumn >= (int)board[0].size() || board[currentRow][currentColumn] != word[index])
        return false;
    
    // Storing current character and marking it as visisted
    char visited = board[currentRow][currentColumn];
    board[currentRow][currentColumn] = '#';

    // Explore
    bool found = traverse(index + 1, currentRow + 1, currentColumn, board, word) ||
                 traverse(index + 1, currentRow - 1, currentColumn, board, word) ||
                 traverse(index + 1, currentRow, currentColumn + 1, board, word) ||
                 traverse(index + 1, currentRow, currentColumn - 1, board, word);

    // Restore
    board[currentRow][currentColumn] = visited;

    return found;
}

bool exist(vector<vector<char>>& board, string word) {
    int rows = board.size(), columns = board[0].size();

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            if(traverse(0, i, j, board, word))
                return true;
        }
    }

    return false;
}

int main() {
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    
    exist(board, word) ? cout<<"True" : cout<<"False";

    return 0;
}