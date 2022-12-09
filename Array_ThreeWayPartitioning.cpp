#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// The bruteforce will be just sort the array, O(Nlog(N))
// void threeWayPartition(vector<int> &array, int a, int b)
// {
//     sort(array.begin(), array.end());
// }

// This approach is more like sorting arrya with 0,1,2's with DNF algorithm, O(N)
void threeWayPartition(vector<int> &arr, int a, int b)
{
    int n = arr.size();
    int start = 0, end = n - 1;

    int i = 0; // iterater which will run upto (i <= end)

    while (i <= end)
    {
        if (arr[i] < a)
        {
            swap(arr[i], arr[start++]);
            i++;
        }
        else if (arr[i] > b)
            swap(arr[i], arr[end--]);
        else
            i++;
    }
}
