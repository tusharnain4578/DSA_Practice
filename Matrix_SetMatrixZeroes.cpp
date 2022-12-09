#include <iostream>
#include <vector>
using namespace std;
// practice --> https://leetcode.com/problems/set-matrix-zeroes/

void setZeroes(vector<vector<int>> &matrix)
{
    // reference --> https://www.youtube.com/watch?v=zgaOU5aInOc

    int m = matrix.size(), n = matrix[0].size();

    bool is_first_row = false, is_first_col = false;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                if (i == 0)
                    is_first_row = true;
                if (j == 0)
                    is_first_col = true;

                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            if (matrix[i][0] == 0 or matrix[0][j] == 0)
                matrix[i][j] = 0;

    if (is_first_row)
        for (int j = 0; j < n; j++) // puting 0 in all block of 1st row
            matrix[0][j] = 0;

    if (is_first_col)
        for (int i = 0; i < m; i++) // puttin 0 in all block of 1st col
            matrix[i][0] = 0;
}