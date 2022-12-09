#include <iostream>
#include <vector>
using namespace std;
// practice --> https://leetcode.com/problems/pascals-triangle-ii/

vector<int> getRow(int rowIndex)
{
    vector<int> a(1, 1);
    for (int i = 1; i <= rowIndex; i++)
    {
        vector<int> b(i + 1, 1);

        for (int j = 1; j < i; j++)
            b[j] = a[j - 1] + a[j];

        a = b;
    }
    return a;
}