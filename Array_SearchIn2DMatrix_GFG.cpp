#include <iostream>
#include <vector>
using namespace std;
// practice --> https://practice.geeksforgeeks.org/problems/search-in-a-matrix17201720/1/#

// Only valid for problem described in GFG

int matSearch(vector<vector<int>> &matrix, int N, int M, int X)
{
    int i = 0, j = M - 1;

    while (i < N and j >= 0)
    {
        if (X == matrix[i][j])
            return 1;
        else if (X > matrix[i][j])
            i++;
        else
            j--;
    }
    return 0;
}