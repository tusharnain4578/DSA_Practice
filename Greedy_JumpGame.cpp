#include <iostream>
using namespace std;

// O(N) solution
bool canReach(int arr[], int N)
{
    if (N <= 1)
        return true;

    if (arr[0] == 0)
        return false;

    int maxReach = arr[0];
    int steps = arr[0];

    for (int i = 1; i < N; i++)
    {
        if (i == N - 1)
            return true;

        maxReach = max(maxReach, i + arr[i]);
        steps--;

        if (steps == 0)
        {
            if (i >= maxReach)
                return false;
            steps = maxReach - i;
        }
    }

    return false;
}