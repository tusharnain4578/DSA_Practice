#include <iostream>
#include <vector>
using namespace std;
// practice --> https://leetcode.com/problems/flood-fill/
void dfs(vector<vector<int>> &image, int i, int j, int m, int n, vector<vector<bool>> &visibility, int old_color, int new_color)
{
    // reference ---> https://www.youtube.com/watch?v=qcNTnDjSffg
    if (i < 0 or j < 0 or i >= m or j >= n or visibility[i][j] or image[i][j] != old_color)
        return;

    visibility[i][j] = true;
    image[i][j] = new_color;

    dfs(image, i + 1, j, m, n, visibility, old_color, new_color);
    dfs(image, i - 1, j, m, n, visibility, old_color, new_color);
    dfs(image, i, j + 1, m, n, visibility, old_color, new_color);
    dfs(image, i, j - 1, m, n, visibility, old_color, new_color);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int m = image.size();
    int n = image[0].size();
    vector<vector<bool>> visibility(m, vector<bool>(n, false));
    int oldColor = image[sr][sc];

    dfs(image, sr, sc, m, n, visibility, oldColor, newColor);

    return image;
}