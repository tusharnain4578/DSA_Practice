#include <iostream>
#include <vector>
using namespace std;
// practice --> https://leetcode.com/problems/pascals-triangle/

vector<vector<int>> generate(int numRows)
{
    // reference ---> https://www.youtube.com/watch?v=U36MSp4-XVI
    vector<vector<int>> pascal;
    for (int i = 0; i < numRows; i++)
    {
        vector<int> t(i + 1, 1);
        for (int j = 1; j < i; j++)
        {
            t[j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
        }

        pascal.push_back(t);
    }
    return pascal;
}

int main()
{
    int num = 5;
    vector<vector<int>> ans = generate(num);

    for (auto &&i : ans)
    {
        for (auto &&j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}