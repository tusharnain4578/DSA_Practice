#include <iostream>
#include <vector>
using namespace std;

int jump(vector<int> &arr)
{
    int N = arr.size();

    if (N <= 1)
        return 0;

    if (arr[0] == 0)
        return -1;

    int maxReach = arr[0];
    int steps = arr[0];
    int jump = 1;

    for (int i = 1; i < N; i++)
    {
        if (i == N - 1)
            return jump;

        maxReach = max(maxReach, i + arr[i]);
        steps--;

        if (steps == 0)
        {
            jump++;
            if (i >= maxReach)
                return -1;
            steps = maxReach - i;
        }
    }

    return -1;
}