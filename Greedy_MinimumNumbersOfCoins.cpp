#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // reference ---> 1, 2, 5, 10, 20, 50, 100, 500, 1000
    int V;
    cin >> V;
    int coins[]{1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = 9;
    vector<int> ans;

    for (int i = n - 1; i >= 0; i--)
    {
        while (V >= coins[i])
        {
            ans.push_back(coins[i]);
            V -= coins[i];
        }
    }

    for (auto &&i : ans)
        cout << i << " ";

    return 0;
}