#include <iostream>
#include <vector>
using namespace std;
// practice --> https://leetcode.com/problems/number-of-enclaves/

void dfs(int i, int j, vector<vector<int>> &grid, int &m, int &n)
{
    if (i < 0 or j < 0 or i >= m or j >= n or grid[i][j] == 0)
        return;

    grid[i][j] = 0;

    dfs(i + 1, j, grid, m, n);
    dfs(i - 1, j, grid, m, n);
    dfs(i, j + 1, grid, m, n);
    dfs(i, j - 1, grid, m, n);
}

int numEnclaves(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    // first removing all the land from the border, which touches the border
    for (int i = 0; i < n; i++) // for upper and lower border
    {
        dfs(0, i, grid, m, n);
        dfs(m - 1, i, grid, m, n);
    }

    for (int i = 0; i < m; i++) // for left and right border
    {
        dfs(i, 0, grid, m, n);
        dfs(i, n - 1, grid, m, n);
    }

    // now rest of the land(if exist) will not be on touch with the border, because above we removed the border touching land

    int count = 0;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j] == 1)
                count++;

    return count;
}