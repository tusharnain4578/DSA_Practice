#include <iostream>
#include <vector>
using namespace std;
// practice --> https://leetcode.com/problems/unique-paths-iii/
// type--> dfs, backtracing

int dfs(int x, int y, int &zeroes, vector<vector<int>> &grid, int &m, int &n)
{
    if (x < 0 or y < 0 or x >= m or y >= n or grid[x][y] == -1)
        return 0;

    if (grid[x][y] == 2)
        return zeroes == -1 ? 1 : 0;

    grid[x][y] = -1;
    zeroes--;

    int total_ways = dfs(x + 1, y, zeroes, grid, m, n) + dfs(x - 1, y, zeroes, grid, m, n) + dfs(x, y + 1, zeroes, grid, m, n) + dfs(x, y - 1, zeroes, grid, m, n);

    // backtracking
    grid[x][y] = 0;
    zeroes++;

    return total_ways;
}

int uniquePathsIII(vector<vector<int>> &grid)
{
    // reference ---> https://www.youtube.com/watch?v=XNKCkX_tHhM
    // same reference also available in help folder

    int zeroes = 0, start_x, start_y;
    int m = grid.size(), n = grid[0].size();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 0)
                zeroes++;
            else if (grid[i][j] == 1)
            {
                start_x = i;
                start_y = j;
            }
        }
    }

    return dfs(start_x, start_y, zeroes, grid, m, n);
}