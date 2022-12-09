#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// practice ---> https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/

// Very Imp //LC-Hard

// for shortest path, always go with BFS (It's optimal, says Google)

// reference --> https://www.youtube.com/watch?v=ID9YJXy3OJk

int shortestPath(vector<vector<int>> &grid, int k)
{
    int m = grid.size(), n = grid[0].size();

    vector<vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    vector<vector<vector<bool>>> vis(m, vector<vector<bool>>(n, vector<bool>(k + 1, false)));

    queue<vector<int>> q;

    q.push({0, 0, k}); // starting point

    int steps = 0;

    while (!q.empty())
    {
        int this_batch_size = q.size();

        while (this_batch_size--)
        {
            int _x = q.front()[0];
            int _y = q.front()[1];
            int _obs = q.front()[2];
            q.pop();

            if (_x == m - 1 and _y == n - 1)
                return steps;

            for (auto const &d : dir)
            {
                int i = _x + d[0];
                int j = _y + d[1];

                if (i >= 0 and i < m and j >= 0 and j < n)
                {
                    if (grid[i][j] == 0 and !vis[i][j][_obs])
                    {
                        q.push({i, j, _obs});
                        vis[i][j][_obs] = true;
                    }
                    else if (grid[i][j] == 1 and _obs > 0 and !vis[i][j][_obs - 1])
                    {
                        q.push({i, j, _obs - 1});
                        vis[i][j][_obs - 1] = true;
                    }
                }
            }
        }

        steps++;
    }

    return -1;
}