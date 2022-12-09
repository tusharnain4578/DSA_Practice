#include <iostream>
#include <vector>
using namespace std;
// practice --> https://practice.geeksforgeeks.org/problems/help-the-old-man3848/1

void rec(int N, int &n, int &count, int source, int destination, int auxilliary, vector<int> &ans)
{
    if (N == 0)
    {
        return;
    }

    rec(N - 1, n, count, source, auxilliary, destination, ans);

    if (count == n)
        return;

    count++;

    if (n == count)
    {
        ans.push_back(source);
        ans.push_back(destination);
        return;
    }

    rec(N - 1, n, count, auxilliary, destination, source, ans);
}

vector<int> shiftPile(int N, int n)
{
    vector<int> ans;
    int count = 0;
    rec(N, n, count, 1, 3, 2, ans);
    return ans;
}