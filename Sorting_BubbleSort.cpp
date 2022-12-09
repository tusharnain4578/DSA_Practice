#include <iostream>
using namespace std;
// practice --> https://practice.geeksforgeeks.org/problems/bubble-sort/1
void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j + 1] < a[j])
                swap(a[j + 1], a[j]);
        }
    }
}

int main()
{
    int a[]{5, 4, 22, 4, 5, 243, 513, 7};
    bubbleSort(a, 8);

    for (auto &&i : a)
    {
        cout << i << " ";
    }

    return 0;
}