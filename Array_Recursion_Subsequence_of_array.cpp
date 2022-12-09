#include <iostream>
#include <vector>
using namespace std;

void subsequence(vector<int> &input, int index, vector<int> &output)
{
    if (index == input.size())
    {
        for (auto it : output)
            cout << it << " ";
        cout << endl;
        return;
    }
    subsequence(input, index + 1, output);
    output.push_back(input[index]);
    subsequence(input, index + 1, output);
    output.pop_back();
}

int main()
{
    vector<int> a{1, 2, 3}, output;
    subsequence(a, 0, output);

    return 0;
}