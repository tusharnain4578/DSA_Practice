#include <iostream>
#include <vector>
using namespace std;

void subsetSumI(vector<int> &arr, int index, int sum, vector<int> &subsetsum)
{
    if (index == arr.size())
    {
        subsetsum.push_back(sum);
        return;
    }
    // not picking
    subsetSumI(arr, index + 1, sum, subsetsum);

    // picking
    subsetSumI(arr, index + 1, sum + arr[index], subsetsum);
}

vector<int> subsetSums(vector<int> arr, int N)
{
    // Write Your Code here
    vector<int> subsetSum;
    subsetSumI(arr, 0, 0, subsetSum);
    return subsetSum;
}

int main()
{
    vector<int> v{1, 2, 3};
    vector<int> ans = subsetSums(v, v.size());
    for (auto &&i : ans)
    {
        cout << i << " ";
    }

    return 0;
}