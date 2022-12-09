#include <iostream>
#include <vector>
using namespace std;

string getPermutation(int n, int k)
{
    // reference ---> https://www.youtube.com/watch?v=wT7gcXLYoao
    // Time Complexity -> O(N^2)
    // Space Complexity -> O(N)
    int fact = 1;
    vector<int> numbers;
    // counting factorial of n-1
    // and making a vector of all numbers upto n
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
        numbers.push_back(i);
    }
    // numbers.push_back(n);

    k--; // decrementing k by 1 because of 0 based indexing

    string ans = "";

    while (!numbers.empty())
    {
        fact /= n;
        ans += to_string(numbers[k / fact]);
        numbers.erase(numbers.begin() + k / fact);
        k = k % fact;
        n--;
    }
    return ans;
}

int main()
{
    int n = 4, k = 17;

    string ans = getPermutation(n, k);
    cout << "The Kth permutation sequence is " << ans << endl;

    return 0;
}