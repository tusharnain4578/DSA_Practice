#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;

bool isPossible(int *arr, int n, int barrier, int s)
{
    int pages_allocated = 0, students = 0;

    for (int i = 0; i < n; i++)
    {
        if (pages_allocated + arr[i] <= barrier)
            pages_allocated += arr[i];
        else
        {
            students++;
            pages_allocated = arr[i];
            if (pages_allocated > barrier)
                return false;
        }
    }
    if (students < s)
        return true;

    return false;
}

int books(int *arr, int n, int s)
{
    // reference ---> https://www.youtube.com/watch?v=gYmWHvRHu-s
    int low = *min_element(arr, arr + n);   // minimum element from array
    int high = accumulate(arr, arr + n, 0); // summation of array
    int res = -1;
    while (low <= high)
    {
        int mid = (low + high) >> 1;

        if (isPossible(arr, n, mid, s))
        {
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    // return low --> this is also correct
    return res;
}

int main()
{
    int arr[]{12, 34, 67, 90};
    int students = 2;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << books(arr, n, students);
    return 0;
}