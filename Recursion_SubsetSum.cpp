#include <iostream>
#include <vector>
using namespace std;

void subset_sum(const vector<int> &v, int index, vector<int> &ans, int sum)
{
    if (index == v.size())
    {
        ans.push_back(sum);
        return;
    }

    // not picking
    subset_sum(v, index + 1, ans, sum);

    // picking
    subset_sum(v, index + 1, ans, sum + v[index]);
}

vector<int> subsetSums(vector<int> arr, int N)
{
    // Write Your Code here
    vector<int> ans;
    subset_sum(arr, 0, ans, 0);
    return ans;
}

int main()
{
    vector<int> arr{3, 1, 2};
    vector<int> ans = subsetSums(arr, arr.size());
    cout << "The sum of each subset is " << endl;
    for (auto sum : ans)
    {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}
