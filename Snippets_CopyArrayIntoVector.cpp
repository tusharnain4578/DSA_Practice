#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int arr[]{1, 2, 3};

    vector<int> v;

    copy(arr, arr + 3, back_inserter(v));

    for (const auto &i : v)
        cout << i << " ";

    return 0;
}