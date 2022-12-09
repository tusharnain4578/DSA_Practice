#include <iostream>
#include <vector>
using namespace std;

// Time-> O(N)
// Space O(N)
// Better approach with constant time is below this function

// reference --> https://www.youtube.com/watch?v=Ebj83h76VUU
int P(int n, int k)
{
    vector<int> fact{1}; // initially putting single element which is 1, factorial of 0

    // generating factorial array, or here we can say dp array
    for (int i = 1; i <= n; i++)
        fact.push_back(i * fact[i - 1]);

    // returning nPr
    return fact[n] / fact[n - k];
}

// Time-> O(N)
// Space O(1)
// Constant time

int P(int n, int k)
{
    // if some platforms gives it "wrong", then just change ans datatyep to long
    int ans = 1;

    for (int i = 0; i < k; i++)
        ans *= (n - i);

    return ans;
}
