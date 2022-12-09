#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
// practice --> https://leetcode.com/problems/intersection-of-two-arrays/
vector<int> intersectionUnsortedArrays(int a[], int b[], int m, int n)
{
    // watch below reference video- recommended for better understanding
    vector<int> res;
    unordered_set<int> s;
    unordered_set<int> finalset;

    for (int i = 0; i < m; i++)
        s.insert(a[i]);

    // s.fing() will return s.end() if the element is not found
    for (int i = 0; i < n; i++)
        if (s.find(b[i]) != s.end())
            finalset.insert(b[i]);

    for (auto i : finalset)
        res.push_back(i);
    return res;
}

int main()
{
    int a[]{9, 2, 4, 6, 8, 4, 3, 7, 3};
    int b[]{6, 3, 6, 8, 4, 2, 5};

    int m = sizeof(a) / sizeof(a[0]);
    int n = sizeof(b) / sizeof(b[0]);

    vector<int> ans = intersectionUnsortedArrays(a, b, m, n);

    for (auto &&i : ans)
    {
        cout << i << " ";
    }

    return 0;
}

// reference ---> https://www.youtube.com/watch?v=d_rH1UJYv2E&ab_channel=CodingSimplified