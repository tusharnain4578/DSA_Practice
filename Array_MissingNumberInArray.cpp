#include <iostream>
#include <vector>
using namespace std;

// practice --> https://practice.geeksforgeeks.org/problems/missing-number-in-array1416/1/
int MissingNumber(vector<int> &array, int n)
{
    int sum = n * (n + 1) / 2;

    for (int i = 0; i < n - 1; i++)
        sum -= array[i];

    return sum;
}

int main()
{
    vector<int> a{1, 2, 3, 5};
    int ans = MissingNumber(a, 5);
    cout << ans;
    return 0;
}