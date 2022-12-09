#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
// practice --> https://leetcode.com/problems/valid-sudoku/
// Refer to video
bool isValidSudoku(vector<vector<char>> &board)
{
    unordered_set<string> s;
    int rows = board.size();
    int cols = board[0].size();

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (board[i][j] != '.')
            {
                char ch = board[i][j];
                string row = "row" + to_string(i) + ch;
                string col = "col" + to_string(j) + ch;
                string box = "box" + to_string(i / 3) + to_string(j / 3) + ch;

                if (s.find(row) != s.end() || s.find(col) != s.end() || s.find(box) != s.end())
                    return false;

                s.insert(row);
                s.insert(col);
                s.insert(box);
            }
        }
    }
    return true;
}
int main()
{
    vector<vector<char>> board{
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    vector<vector<char>> board2{
        {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    cout << isValidSudoku(board) << endl;
    cout << isValidSudoku(board2) << endl;

    return 0;
}
