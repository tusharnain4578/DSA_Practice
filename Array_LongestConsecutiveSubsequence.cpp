#include <iostream>
#include <unordered_set>
using namespace std;
// practice --> https://leetcode.com/problems/longest-consecutive-sequence/
int findLongestConseqSubseq(int arr[], int N)
{
    // reference ---> https://www.youtube.com/watch?v=CBFn7zWMOBQ
    unordered_set<int> s;
    int ans = 0;

    for (int i = 0; i < N; i++)
        s.insert(arr[i]);

    for (int i = 0; i < N; i++)
    {
        if (s.find(arr[i] - 1) != s.end())
            continue;

        int count = 1;
        int current = arr[i] + 1;
        while (s.find(current) != s.end())
        {
            count++;
            current++;
        }
        ans = max(count, ans);
    }
    return ans;
}
int main()
{
    int arr[]{1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << findLongestConseqSubseq(arr, size);

    return 0;
}