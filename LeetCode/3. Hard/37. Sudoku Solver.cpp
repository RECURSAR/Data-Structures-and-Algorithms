#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

void printSudokuBoard(const vector<vector<char>> &board);

bool isValid(char ch, int row, int column, vector<vector<char>> &board) {
    int boxRow = (row / 3) * 3, boxColumn = (column / 3) * 3;

    for(int i = 0; i < 9; i++) {
        if(board[row][i] == ch)
            return false;
        if(board[i][column] == ch)
            return false;
        if(board[boxRow + i / 3][boxColumn + i % 3] == ch)
            return false;
    }

    return true;
}

bool solve(int position, vector<vector<char>> &board) {
    if(position == 81)
        return true;

    int row = position / 9, column = position % 9;

    if(board[row][column] != '.')
        return solve(position + 1, board);
    
    for(char ch = '1'; ch <= '9'; ch++) {
        if(isValid(ch, row, column, board)) {
            board[row][column] = ch;

            if(solve(position + 1, board))
                return true;
            
            // Backtrack
            board[row][column] = '.';
        }
    }

    return false;
}

void solveSudoku(vector<vector<char>>& board) {
    solve(0, board);
}

int main() {
    vector<vector<char>> board = {
                                    {'5','3','.','.','7','.','.','.','.'},
                                    {'6','.','.','1','9','5','.','.','.'},
                                    {'.','9','8','.','.','.','.','6','.'},
                                    {'8','.','.','.','6','.','.','.','3'},
                                    {'4','.','.','8','.','3','.','.','1'},
                                    {'7','.','.','.','2','.','.','.','6'},
                                    {'.','6','.','.','.','.','2','8','.'},
                                    {'.','.','.','4','1','9','.','.','5'},
                                    {'.','.','.','.','8','.','.','7','9'}
                                };

    solveSudoku(board);
    printSudokuBoard(board);

    return 0;
}

// Helper function to print the sudoku board
void printSudokuBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0) {
            cout << "+-------+-------+-------+\n";
        }

        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0) {
                cout << "| ";
            }

            cout << board[i][j] << ' ';
        }

        cout << "|\n";
    }

    cout << "+-------+-------+-------+\n";
}