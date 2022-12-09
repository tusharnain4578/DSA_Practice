#include <iostream>
#include <vector>
using namespace std;

void claculateLPS_Array(string &str, vector<int> &arr)
{
    int j = 0;
    arr[0] = 0; // first element of lps array will always be 0

    int i = 1;
    int n = str.size();

    while (i < n)
    {
        if (str[i] == str[j])
        {
            j++;
            arr[i] = j;
            i++;
        }
        else
        {
            if (j == 0)
            {
                arr[i] = 0;
                i++;
            }
            else
            {
                j = arr[j - 1];
            }
        }
    }
}

vector<int> KMP(string &text, string &pat)
{
    vector<int> ans;

    int text_size = text.size();
    int pat_size = pat.size();

    vector<int> lps(pat_size);

    claculateLPS_Array(pat, lps);

    int i = 0, j = 0;

    while (i < text_size)
    {
        if (text[i] == pat[j])
            i++, j++;

        if (j == pat_size)
            ans.push_back(i - j);

        if (i < text_size and text[i] != pat[j])
        {
            if (j == 0)
                i++;
            else
                j = lps[j - 1];
        }
    }

    return ans;
}

int main()
{
    string text = "ABABABABCABABDAAaabxaayaabBABCABABBACDABAaabxaayaabBCABABABABCABAB";
    string pat = "aabxaayaab";

    vector<int> res = KMP(text, pat);

    for (int &i : res)
        cout << i << endl;

    return 0;
}