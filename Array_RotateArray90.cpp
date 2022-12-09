#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// practice --> https://leetcode.com/problems/rotate-image/
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    // Algo for transpose of only NxN matrix(square matrix)
    // This method of transpose(in place) only works on N*N matrix
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            swap(matrix[i][j], matrix[j][i]);

    for (int i = 0; i < n; i++)
        reverse(matrix[i].begin(), matrix[i].end());
}
int main()
{
    vector<vector<int>> matrix{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    rotate(matrix);

    for (auto it = matrix.begin(); it != matrix.end(); it++)
    {
        for (auto jt = it->begin(); jt != it->end(); jt++)
            cout << *jt << " ";
        cout << endl;
    }

    return 0;
}
