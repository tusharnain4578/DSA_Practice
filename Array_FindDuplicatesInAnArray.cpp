#include <iostream>
#include <vector>
using namespace std;
// practice --> https://practice.geeksforgeeks.org/problems/find-duplicates-in-an-array/1
vector<int> duplicates(int arr[], int n)
{
    // i recommend to deep dive in this to understand better
    vector<int> res;
    for (int i = 0; i < n; i++)
        arr[arr[i] % n] += n;

    for (int i = 0; i < n; i++)
        if (arr[i] / n > 1)
            res.push_back(i);

    if (res.empty())
        res.push_back(-1);
    return res;
}

int main()
{
    int arr[]{2, 3, 1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> ans = duplicates(arr, size);
    for (auto &&i : ans)
    {
        cout << i << " ";
    }

    return 0;
}

// reference ---> https://www.youtube.com/watch?v=kV37sZV9pgk