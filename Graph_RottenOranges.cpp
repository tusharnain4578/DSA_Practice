#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// practice --> https://leetcode.com/problems/rotting-oranges/
int orangesRotting(vector<vector<int>> &grid)
{
    // reference ---> https://www.youtube.com/watch?v=H-p_MaL0g-A&t=1091s

    queue<pair<int, int>> q;

    int r = grid.size();
    int c = grid[0].size();

    // pushing rotten oranges indexes
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (grid[i][j] == 2)
                q.push({i, j});

    q.push({-1, -1}); // pushing (-1, -1) for each time unit partition, {-1, -1} is a partition line or block
    int count = 0;
    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;

        if (i == -1 and j == -1 and q.size() == 1) // last partition line
            break;
        else if (i == -1 and j == -1 and q.size() > 1) // any middle partition line
        {
            count++;
            q.pop();
            q.push({-1, -1}); // putting partion line for other partition
        }
        else
        {
            if (i - 1 >= 0 and grid[i - 1][j] == 1) // up
            {
                grid[i - 1][j] = 2;
                q.push({i - 1, j});
            }

            if (i + 1 < r and grid[i + 1][j] == 1) // down
            {
                grid[i + 1][j] = 2;
                q.push({i + 1, j});
            }

            if (j - 1 >= 0 and grid[i][j - 1] == 1) // left
            {
                grid[i][j - 1] = 2;
                q.push({i, j - 1});
            }

            if (j + 1 < c and grid[i][j + 1] == 1) // right
            {
                grid[i][j + 1] = 2;
                q.push({i, j + 1});
            }
            q.pop();
        }
    }

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (grid[i][j] == 1)
                return -1;

    return count;
}

int main()
{
    vector<vector<int>> grid{{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
    cout << orangesRotting(grid);

    return 0;
}

//
//
//
// Other method

int orangesRotting(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();

    queue<pair<int, int>> q;
    bool fresh = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push(make_pair(i, j));
            }
            else if (grid[i][j] == 1)
            {
                fresh = 1;
            }
        }
    }

    if (!fresh)
        return 0;

    int time = 0;

    while (!q.empty())
    {
        int qSize = q.size();
        bool temp = 0;

        while (qSize != 0)
        {
            int i = q.front().first, j = q.front().second;
            q.pop();

            vector<int> _x{1, -1, 0, 0};
            vector<int> _y{0, 0, 1, -1};

            for (int k = 0; k < 4; k++)
            {
                int x = i + _x[k],
                    y = j + _y[k];

                // if coordinates are valid
                if (x >= 0 and x < m and y >= 0 and y < n and grid[x][y] == 1)
                {
                    temp = 1;
                    grid[x][y] = 2; // rotting them
                    q.push(make_pair(x, y));
                }
            }
            qSize--;
        }
        if (temp)
            time++;
    }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j] == 1)
                return -1;

    return time;
}