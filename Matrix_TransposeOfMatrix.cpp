#include <iostream>
#include <vector>
using namespace std;
// practice --> https://leetcode.com/problems/transpose-matrix/

vector<vector<int>> transpose(vector<vector<int>> &matrix)
{

    int m = matrix.size(), n = matrix[0].size();

    vector<vector<int>> v(n, vector<int>(m)); // in transpose, all columns will become rows and rows becomes columns, means a 3x4 matrix's transpose will be 4x3

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            v[i][j] = matrix[j][i];

    return v;
}

// We only can transpose a matrix *in place, if it's N*N, below is the code, see below code

vector<vector<int>> transpose(vector<vector<int>> &matrix)
{

    int N = matrix.size();

    // Algo for transpose of only NxN matrix(square matrix)
    // This method of transpose(in place) only works on N*N matrix
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            swap(matrix[i][j], matrix[j][i]);

    return matrix;
}