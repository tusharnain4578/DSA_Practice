#include <iostream>
using namespace std;
//          SORTED   ARRAY    ONLY

// UNION
void unionOfSortedArrays(int a[], int b[], int m, int n)
{
    int i = 0, j = 0;

    while (i < m && j < n)
    {
        if (a[i] < b[j])
            cout << a[i++] << " ";
        else if (b[j] < a[i])
            cout << b[j++] << " ";
        else
        {
            cout << a[i] << " ";
            i++;
            j++;
        }
    }
    while (i < m)
        cout << a[i++] << " ";

    while (j < n)
        cout << b[j++] << " ";
}

// Intersection
void intersectionOfSorteArraya(int a[], int b[], int m, int n)
{
    int i = 0;
    int j = 0;

    while (i < m && j < n)
    {
        if (a[i] < b[j])
            i++;
        else if (b[j] < a[i])
            j++;
        else
        {
            cout << a[i] << " ";
            i++;
            j++;
        }
    }
}

int main()
{
    int a[]{1, 2, 3, 4, 5, 6, 8, 99};
    int b[]{4, 6, 4, 99, 100, 120};
    int m = sizeof(a) / sizeof(a[0]);
    int n = sizeof(b) / sizeof(b[0]);

    cout << "Union -> ";
    unionOfSortedArrays(a, b, m, n);
    cout << endl;
    cout << "Intersection -> ";
    intersectionOfSorteArraya(a, b, m, n);

    return 0;
}

// reference ---> https://www.geeksforgeeks.org/union-and-intersection-of-two-sorted-arrays-2/