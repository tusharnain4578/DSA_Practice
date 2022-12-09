#include <iostream>
#include <vector>
using namespace std;
// practice --> https://leetcode.com/problems/surrounded-regions/

void flag(vector<vector<char>> &board, int &m, int &n, int row, int col)
{
    if (row < 0 or col < 0 or row == m or col == n or board[row][col] != 'O')
        return;

    board[row][col] = '$'; // can use anything, it's just a flag btw

    // now flag surrounding O's (if exists)
    flag(board, m, n, row - 1, col);
    flag(board, m, n, row + 1, col);
    flag(board, m, n, row, col - 1);
    flag(board, m, n, row, col + 1);
}

void solve(vector<vector<char>> &board)
{
    int m = board.size(), n = board[0].size();
    // flagging borders

    // first flagging upper and bottom rows
    for (int i = 0; i < n; i++)
    {
        flag(board, m, n, 0, i);
        flag(board, m, n, m - 1, i);
    }

    // now flagging leftmost and rightmost columns
    for (int i = 0; i < m; i++)
    {
        flag(board, m, n, i, 0);
        flag(board, m, n, i, n - 1);
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 'O')
                board[i][j] = 'X';
            else if (board[i][j] == '$')
                board[i][j] = 'O';
        }
    }
}