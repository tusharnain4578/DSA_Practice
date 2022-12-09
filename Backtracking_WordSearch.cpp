#include <iostream>
#include <vector>
using namespace std;

// dfs
bool dfs(vector<vector<char>> &board, vector<vector<bool>> &vis, int i, int j, int &curr_word_index, string &word)
{
    if (curr_word_index == word.size())
        return true;

    if (i < 0 or j < 0 or i >= board.size() or j >= board[0].size() or vis[i][j] or board[i][j] != word[curr_word_index])
        return false;

    vis[i][j] = true;
    curr_word_index++;

    // if(up or down or left or right) return true
    if (dfs(board, vis, i - 1, j, curr_word_index, word) or
        dfs(board, vis, i + 1, j, curr_word_index, word) or
        dfs(board, vis, i, j - 1, curr_word_index, word) or
        dfs(board, vis, i, j + 1, curr_word_index, word))
        return true;

    vis[i][j] = false;
    curr_word_index--;

    return false;
}

bool exist(vector<vector<char>> &board, string word)
{
    vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size(), false));
    int curr_word_index = 0;

    for (int i = 0; i < board.size(); i++)
        for (int j = 0; j < board[0].size(); j++)
            if (dfs(board, vis, i, j, curr_word_index, word))
                return true;

    return false;
}

// ************************************
// ************************************
// ************************************
// ************************************
// ************************************

// Another approach where we do not need to use visited matrix

bool dfs(vector<vector<char>> &board, int i, int j, int &curr_word_index, string &word)
{
    if (curr_word_index == word.size())
        return true;

    if (i < 0 or j < 0 or i >= board.size() or j >= board[0].size() or board[i][j] == '$' or board[i][j] != word[curr_word_index])
        return false;

    int bak = board[i][j];
    board[i][j] = '$'; // instead of using visited matrix, we're changing the actual value
    // we will re assign the same value on backtracing
    curr_word_index++;

    // if(up or down or left or right) return true
    if (dfs(board, i - 1, j, curr_word_index, word) or
        dfs(board, i + 1, j, curr_word_index, word) or
        dfs(board, i, j - 1, curr_word_index, word) or
        dfs(board, i, j + 1, curr_word_index, word))
        return true;

    board[i][j] = bak; // reassigning old value
    curr_word_index--;

    return false;
}

bool exist(vector<vector<char>> &board, string word)
{
    int curr_word_index = 0;

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (dfs(board, i, j, curr_word_index, word))
                return true;
        }
    }

    return false;
}