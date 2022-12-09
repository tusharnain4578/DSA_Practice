#include <iostream>
#include <vector>
using namespace std;
// practice --> https://leetcode.com/problems/spiral-matrix/

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    // reference ---> https://www.youtube.com/watch?v=1ZGJzvkcLsA
    int m = matrix.size(), n = matrix[0].size();
    vector<int> spiral;

    int top = 0, bottom = m - 1, left = 0, right = n - 1;

    int direction = 0;
    // 0 -> left to right
    // 1 -> top to bottom
    // 2 -> right to left
    // 3 -> bottom to top

    while (top <= bottom and left <= right)
    {
        if (direction == 0)
        {
            for (int i = left; i <= right; i++)
                spiral.push_back(matrix[top][i]);

            top++;
        }
        else if (direction == 1)
        {
            for (int i = top; i <= bottom; i++)
                spiral.push_back(matrix[i][right]);

            right--;
        }
        else if (direction == 2)
        {
            for (int i = right; i >= left; i--)
                spiral.push_back(matrix[bottom][i]);

            bottom--;
        }
        else // if direction is 3
        {
            for (int i = bottom; i >= top; i--)
                spiral.push_back(matrix[i][left]);

            left++;
        }

        direction = (direction + 1) % 4;
    }

    return spiral;
}