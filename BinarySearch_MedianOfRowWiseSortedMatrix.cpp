#include <iostream>
#include <vector>
using namespace std;

int countSmallerThanMid(const vector<int> &row, int target)
{
    // reference ---> https://www.geeksforgeeks.org/find-median-row-wise-sorted-matrix/
    int low = 0, high = row.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (row[mid] <= target) // the equal case of binary search will combine with this condition
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int findMedian(vector<vector<int>> &A)
{
    int last_element_index_in_row = A[0].size() - 1;
    int min = INT_MAX, max = INT_MIN;

    for (int i = 0; i < A.size(); i++)
    {
        if (A[i][0] < min)
            min = A[i][0];

        if (A[i][last_element_index_in_row] > max)
            max = A[i][last_element_index_in_row];
    }

    int total_elements = A.size() * A[0].size();

    while (min <= max)
    {
        int mid = (min + max) / 2;

        int count_of_elements_less_than_mid = 0;

        for (int i = 0; i < A.size(); i++)
            count_of_elements_less_than_mid += countSmallerThanMid(A[i], mid);

        if (count_of_elements_less_than_mid <= total_elements / 2)
            min = mid + 1;
        else
            max = mid - 1;
    }

    return min;
}

int main()
{
    vector<vector<int>> A{{1, 3, 5},
                          {2, 6, 9},
                          {3, 6, 9}};
    // 1, 2, 3, 3, 5, 6, 6, 9, 9

    cout << findMedian(A);

    return 0;
}