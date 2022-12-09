#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// practice --> https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1
vector<int> countDistinct(int arr[], int n, int k)
{
    // reference ---> https://www.youtube.com/watch?v=x8O9XocEioI
    vector<int> ans;

    unordered_map<int, int> m;
    int dist_count = 0;

    for (int i = 0; i < k; i++)
    {
        m[arr[i]]++;

        if (m[arr[i]] == 1)
            dist_count++;
    }

    ans.push_back(dist_count);

    for (int i = k; i < n; i++)
    {
        if (m[arr[i - k]] == 1)
            dist_count--;

        m[arr[i - k]]--;

        m[arr[i]]++;
        if (m[arr[i]] == 1)
            dist_count++;

        ans.push_back(dist_count);
    }
    return ans;
}