#include <iostream>
#include <unordered_map>
using namespace std;
// practice --> https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1/

// the sorting and 2 pointer approach won't work here, you'll know once you see this example
//  {1, 1, 1, 1} ---> it's answer is 6

int getPairsCount(int arr[], int n, int k)
{
    // see the reference below, highly recommended, coz this ain't no easy
    unordered_map<int, int> m;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (m.find(k - arr[i]) != m.end())
        {
            count += m[k - arr[i]];
        }
        m[arr[i]]++;
    }
    return count;
}

int main()
{
    int arr[]{1, 5, 7, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 6;
    int ans = getPairsCount(arr, size, k);
    cout << ans << endl;

    return 0;
}
// reference --->https://www.youtube.com/watch?v=5L9Jrehvoew