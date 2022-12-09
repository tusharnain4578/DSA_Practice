#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool is_safe(const vector<vector<int>> &m, const int &n, int x, int y, vector<vector<int>> &visited)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && m[x][y] == 1)
        return true;

    return false;
}

void solve(const vector<vector<int>> &m, const int &n, int x, int y, string &path, vector<string> &ans, vector<vector<int>> &visited)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    // 4 choices -> Up, Right, Down, Left

    // UP
    if (is_safe(m, n, x - 1, y, visited))
    {
        path.push_back('U');
        solve(m, n, x - 1, y, path, ans, visited);
        path.pop_back();
    }

    // Right
    if (is_safe(m, n, x, y + 1, visited))
    {
        path.push_back('R');
        solve(m, n, x, y + 1, path, ans, visited);
        path.pop_back();
    }

    // Down
    if (is_safe(m, n, x + 1, y, visited))
    {
        path.push_back('D');
        solve(m, n, x + 1, y, path, ans, visited);
        path.pop_back();
    }

    // Left
    if (is_safe(m, n, x, y - 1, visited))
    {
        path.push_back('L');
        solve(m, n, x, y - 1, path, ans, visited);
        path.pop_back();
    }

    visited[x][y] = 0;
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    // reference ---> https://www.youtube.com/watch?v=GqtyVD-x_jY
    if (m[0][0] == 0)
        return {};

    vector<vector<int>> visited = m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            visited[i][j] = 0;

    string path = "";
    vector<string> ans;
    // 0, 0 are the starting point of the rat
    solve(m, n, 0, 0, path, ans, visited);

    // sorting the ans lexicographically
    sort(ans.begin(), ans.end());

    return ans;
}

int main()
{
    vector<vector<int>> m{{1, 0, 0, 0},
                          {1, 1, 0, 1},
                          {1, 1, 0, 0},
                          {0, 1, 1, 1}};
    int n = m.size();

    vector<string> ans = findPath(m, n);

    for (auto &&i : ans)
        cout << i << " ";

    return 0;
}