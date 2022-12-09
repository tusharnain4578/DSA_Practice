#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// practice --> https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1/

int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
{
    // converting to 0 based indexing
    int tx = TargetPos[0] - 1, ty = TargetPos[1] - 1;
    int kx = KnightPos[0] - 1, ky = KnightPos[1] - 1;

    if (kx == tx and ky == ty)
        return 0;

    vector<vector<bool>> vis(N, vector<bool>(N, false));

    queue<pair<int, int>> q;
    vis[kx][ky] = true;
    q.push(make_pair(kx, ky));

    int ans = 0;

    while (!q.empty())
    {
        int qSize = q.size();
        ans++;

        while (qSize != 0)
        {
            int i = q.front().first, j = q.front().second;
            q.pop();

            vector<int> _x{1, 1, -1, -1, 2, 2, -2, -2};
            vector<int> _y{2, -2, 2, -2, 1, -1, 1, -1};

            for (int k = 0; k < 4; k++)
            {
                int x = i + _x[k],
                    y = j + _y[k];

                if (x == tx and y == ty)
                    return ans;

                if (x >= 0 and y >= 0 and x < N and y < N and !vis[x][y])
                {
                    vis[x][y] = true;
                    q.push(make_pair(x, y));
                }
            }
            qSize--;
        }
    }

    return ans;
}