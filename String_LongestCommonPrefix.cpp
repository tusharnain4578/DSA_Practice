#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    string ans = strs[0]; // taking first string as answer

    for (int i = 1; i < strs.size(); i++) // running loop on rest of the loop
    {
        int a = 0, b = 0; // taking 2 pointers for traversing ans ans ith string

        while (a < ans.size() && b < strs[i].size())
        {
            if (ans[a] == strs[i][b]) // as long as the both string has same chars, keep incrementing the pointers else break
                a++, b++;
            else
                break;
        }

        ans = ans.substr(0, a); // the answer till now will be substring on the answer from beginning upto a
    }

    return ans;
}
int main()
{
    vector<string> strs{"flower", "flow", "flight"};
    cout << longestCommonPrefix(strs);

    return 0;
}