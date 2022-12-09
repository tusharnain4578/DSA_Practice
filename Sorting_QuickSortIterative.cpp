#include <iostream>
#include <stack>
using namespace std;
// practice --> https://practice.geeksforgeeks.org/problems/quick-sort/1
int partition(int a[], int low, int high)
{
    int i = low;
    int j = high;
    int pivot = a[low];

    while (i < j)
    {
        while (a[i] <= pivot)
            i++;

        while (a[j] > pivot)
            j--;

        if (i < j)
            swap(a[i], a[j]);
    }
    swap(a[low], a[j]);
    return j;
}

void IterativeQuickSort(int a[], int low, int high)
{
    if (low < high)
    {
        stack<int> st;
        st.push(low);
        st.push(high);

        while (!st.empty())
        {
            high = st.top();
            st.pop();
            low = st.top();
            st.pop();
            int p = partition(a, low, high);

            if (p - 1 > low)
            {
                st.push(low);
                st.push(p - 1);
            }
            if (p + 1 < high)
            {
                st.push(p + 1);
                st.push(high);
            }
        }
    }
}

void displayArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

int main()
{
    int a[]{1, 5, 3, 2};
    int size = sizeof(a) / sizeof(a[0]);
    IterativeQuickSort(a, 0, size - 1);
    displayArray(a, size);
    return 0;
}

// Reference ---> youtube.com/watch?v=qBo_9cgBVpk