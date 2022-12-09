#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>> &grid, int i, int j, int &m, int &n)
{
    if (i < 0 or j < 0 or i >= m or j >= n or grid[i][j] == '0')
        return;

    grid[i][j] = '0';

    dfs(grid, i - 1, j, m, n); // up
    dfs(grid, i, j + 1, m, n); // right
    dfs(grid, i + 1, j, m, n); // down
    dfs(grid, i, j - 1, m, n); // left
}

int numIslands(vector<vector<char>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    int number_of_islands = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '1')
            {
                number_of_islands++;
                dfs(grid, i, j, m, n); // dfs for making the island visited
            }
        }
    }

    return number_of_islands;
}