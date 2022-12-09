// Problem also known as Common Elements
// Arrays are sorted
#include <iostream>
#include <vector>
using namespace std;
// practice --> https://practice.geeksforgeeks.org/problems/common-elements1132/1
vector<int> commonElements(int a[], int b[], int c[], int n1, int n2, int n3)
{
    // reference below - recommended
    vector<int> res;
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2 && k < n3)
    {
        if (a[i] == b[j] && b[j] == c[k])
        {
            res.push_back(a[i]);
            i++;
            j++;
            k++;
        }
        else if (a[i] < b[j])
            i++;
        else if (b[j] < c[k])
            j++;
        else
            k++;

        // for unique elements
        while (i > 0 and a[i] == a[i - 1])
            i++;
        while (j > 0 and b[j] == b[j - 1])
            j++;
        while (k > 0 and c[k] == c[k - 1])
            k++;
    }
    if (res.empty())
        res.push_back(-1);

    return res;
}

int main()
{
    int a[]{1, 5, 10, 20, 40, 80};
    int b[]{6, 7, 20, 80, 100};
    int c[]{3, 4, 15, 20, 30, 70, 80, 120};

    int n1 = sizeof(a) / sizeof(a[0]);
    int n2 = sizeof(b) / sizeof(b[0]);
    int n3 = sizeof(c) / sizeof(c[0]);

    vector<int> ans = commonElements(a, b, c, n1, n2, n3);
    for (auto &&i : ans)
    {
        cout << i << " ";
    }

    return 0;
}

// reference ---> https://www.youtube.com/watch?v=ajWCEu1razQ