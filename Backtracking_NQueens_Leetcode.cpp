#include <iostream>
#include <vector>
using namespace std;
// practice --> https://leetcode.com/problems/n-queens/

bool isSafe(vector<string> &board, int row, int col, int &n)
{
    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i] == 'Q')
            return false;

    for (i = row, j = col; i >= 0 and j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return false;

    for (i = row, j = col; i < n and j >= 0; i++, j--)
        if (board[i][j] == 'Q')
            return false;

    return true;
}

void solve(vector<string> &board, vector<vector<string>> &result, int col, int &n)
{
    if (col == n)
    {
        result.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(board, row, col, n))
        {
            board[row][col] = 'Q';

            solve(board, result, col + 1, n);

            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<string> board(n);
    for (auto &i : board)
        for (int j = 0; j < n; j++)
            i.push_back('.');

    vector<vector<string>> result;

    solve(board, result, 0, n);

    return result;
}