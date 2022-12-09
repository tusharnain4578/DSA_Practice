#include <iostream>
#include <vector>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/sieve-of-eratosthenes5242/1

vector<int> sieveOfEratosthenes(int N)
{
    vector<int> ans;
    vector<bool> sieve(N + 1, true);

    for (int i = 2; i <= N; i++)
    {
        if (sieve[i])
        {
            ans.push_back(i);
            for (int j = i * 2; j <= N; j += i)
                sieve[j] = false;
        }
    }

    return ans;
}

int main()
{
    int N = 10000000;
    vector<int> primes = sieveOfEratosthenes(N);

    for (auto &i : primes)
        cout << i << " ";

    return 0;
}