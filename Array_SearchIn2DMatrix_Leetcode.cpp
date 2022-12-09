#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    // This algorithm is based on leetcode version of this problem
    // problem link -> https://leetcode.com/problems/search-a-2d-matrix/
    // binary search
    int m = matrix.size();
    int n = matrix[0].size();

    int low = 0, high = m * n - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        int mid_x = mid / n; // for x coordinatet, divide mid by n(total collumns)
        int mid_y = mid % n; // for x coordinatet, mod mid by n(total collumns)

        if (matrix[mid_x][mid_y] == target)
            return true;
        else if (matrix[mid_x][mid_y] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7},
                                  {10, 11, 16, 20},
                                  {23, 30, 34, 60}};
    int target = 34;

    if (searchMatrix(matrix, target))
        cout << "found";
    else
        cout << "not found";

    return 0;
}