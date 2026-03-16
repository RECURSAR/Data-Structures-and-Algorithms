#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

// Brute-Force Approach
/*
bool isSafe(int n, int row, int column, vector<vector<char>> &board) {
    // Check all columns to the left in the same row
    for(int j = 0; j < column; j++) {
        if(board[row][j] == 'Q')
            return false;
    }

    // Check upper-left diagonal
    for(int i = row, j = column; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j] == 'Q')
            return false;
    }

    // Check lower-left diagonal
    for(int i = row, j = column; i < n && j >= 0; i++, j--) {
        if(board[i][j] == 'Q')
            return false;
    }

    return true;
}

void solve(int column, int n, vector<vector<string>> &result, vector<vector<char>> &board) {
    if(column == n) {
        vector<string> temp;
        for(int i = 0; i < n; i++) {
            string row(board[i].begin(), board[i].end());
            temp.push_back(row);
        }

        result.push_back(temp);
        return;
    }

    for(int row = 0; row < n; row++) {
        // Placing queen only if it is safe
        if(isSafe(n, row, column, board)) {
            // Queen Placed
            board[row][column] = 'Q';

            // Moving to next column
            solve(column + 1, n, result, board);

            // Backtrack and remove Queen
            board[row][column] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;

    vector<vector<char>> board(n, vector<char>(n, '.'));

    solve(0, n, result, board);

    return result;
}
*/

// Optimal Approach
void solve(int column, int n, vector<vector<string>> &result, vector<string> &board, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal) {
    if(column == n) {
        result.push_back(board);
        return;
    }

    for(int row = 0; row < n; row++) {
        if(leftRow[row] == 0 && lowerDiagonal[row + column] == 0 && upperDiagonal[n - 1 + column - row] == 0) {
            // Place Queen
            board[row][column] = 'Q';

            // Marking Rows and Diagonals
            leftRow[row] = 1;
            lowerDiagonal[row + column] = 1;
            upperDiagonal[n - 1 + column - row] = 1;

            solve(column + 1, n, result, board, leftRow, upperDiagonal, lowerDiagonal);

            // Backtrack and remove Queen
            board[row][column] = '.';
            leftRow[row] = 0;
            lowerDiagonal[row + column] = 0;
            upperDiagonal[n - 1 + column - row] = 0;
        }
    }

}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;

    vector<string> board(n, string(n, '.'));

    vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);

    solve(0, n, result, board, leftRow, upperDiagonal, lowerDiagonal);

    return result;
}

int main() {
    int n = 4;
    
    vector<vector<string>> result = solveNQueens(n);
    for(auto res : result) {
        for(auto r : res)
            cout<<r<<" ";
        cout<<endl;
    }

    return 0;
}