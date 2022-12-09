#include <iostream>
#include <unordered_set>
using namespace std;
// practice -> https://practice.geeksforgeeks.org/problems/first-repeating-element4018/1/

int firstRepeated(int arr[], int n)
{
    // code here
    unordered_set<int> s;
    int first_repeating_element = -2; // making it -2 instead of -1 because i returned it with +1
    for (int i = n - 1; i >= 0; i--)
    {
        if (s.find(arr[i]) != s.end())
            first_repeating_element = i;
        else
            s.insert(arr[i]);
    }
    return first_repeating_element + 1;
}

int main()
{
    int arr[]{1, 5, 3, 4, 3, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "First repeated element is at index -> ";
    cout << firstRepeated(arr, size);

    return 0;
}