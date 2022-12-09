#include <iostream>
#include <unordered_set>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/array-subset-of-another-array2317/1

string isSubset(int a1[], int a2[], int m, int n)
{
    unordered_set<int> s;

    for (int i = 0; i < m; i++)
        s.insert(a1[i]);

    for (int i = 0; i < n; i++)
        if (s.find(a2[i]) == s.end())
            return "No";

    return "Yes";
}