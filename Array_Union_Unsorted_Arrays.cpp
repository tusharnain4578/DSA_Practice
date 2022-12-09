#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// This can also be done in the same way using maps, but if you don't want to use sets or maps, you have to sort both the arrays first, and then you can apply the same method as Union of Sorted Arrays
vector<int> unionUnsortedArray(int a[], int b[], int m, int n)
{
    vector<int> res;
    unordered_set<int> s;
    for (int i = 0; i < m; i++)
        s.insert(a[i]);
    for (int i = 0; i < n; i++)
        s.insert(b[i]);

    for (auto it : s)
        res.push_back(it);

    return res;
}

int main()
{
    int a[]{1, 2, 3, 4, 5, 6, 8, 99};
    int b[]{4, 6, 99, 100, 120};
    int m = sizeof(a) / sizeof(a[0]);
    int n = sizeof(b) / sizeof(b[0]);

    cout << "Union -> ";
    vector<int> ans = unionUnsortedArray(a, b, m, n);

    for (auto &&i : ans)
    {
        cout << i << " ";
    }

    return 0;
}