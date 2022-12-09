#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// practice ---> https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/

// Leetcode Medium

// BFS

bool isValid(const int &x, const int &y, const int &m, const int &n)
{
    return x >= 0 and y >= 0 and x < m and y < n;
}

int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
{
    int m = maze.size(), n = maze[0].size();

    vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    queue<pair<int, int>> q;

    q.push(make_pair(entrance[0], entrance[1]));
    maze[entrance[0]][entrance[1]] = '+';

    int steps = 0;

    while (!q.empty())
    {
        int qsize = q.size();

        while (qsize--)
        {

            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == 0 or y == 0 or x == m - 1 or y == n - 1)
                if (x != entrance[0] or y != entrance[1])
                    return steps;

            for (const auto &dir : directions)
            {
                int newX = x + dir.first;
                int newY = y + dir.second;

                if (isValid(newX, newY, m, n) and maze[newX][newY] != '+')
                {
                    maze[newX][newY] = '+';
                    q.push(make_pair(newX, newY));
                }
            }
        }
        steps++;
    }

    return -1;
}