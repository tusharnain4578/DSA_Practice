#include <iostream>
using namespace std;
// practice --> https://practice.geeksforgeeks.org/problems/selection-sort/1
void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIndex])
                minIndex = j;
        }
        swap(a[i], a[minIndex]);
    }
}

int main()
{
    int a[]{5, 2, 3, 1, 4, 2, 3};
    selectionSort(a, 7);
    for (auto &&i : a)
    {
        cout << i << " ";
    }

    return 0;
}

// Reference Image
//  http://tusharjs.rf.gd/_essesntials_dont_delete/SelectionSortHint.png
