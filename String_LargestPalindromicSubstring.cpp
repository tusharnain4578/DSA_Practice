#include <iostream>
using namespace std;

string longestPalindrome(string S)
{
    // reference ---> https://www.youtube.com/watch?v=jCOJk4UyO8w

    int n = S.size();

    int ans_begin_index = 0, ans_length = 1; // pointers for final solution span

    int l, h; // pointers for taking span

    for (int i = 0; i < n; i++)
    {
        // for even case
        l = i;
        h = i + 1;

        while (i >= 0 and h < n and S[l] == S[h])
        {
            if (h - l + 1 > ans_length)
            {
                ans_begin_index = l;
                ans_length = h - l + 1;
            }
            l--, h++;
        }

        // for odd case
        l = i - 1;
        h = i + 1;

        while (i >= 0 and h < n and S[l] == S[h])
        {
            if (h - l + 1 > ans_length)
            {
                ans_begin_index = l;
                ans_length = h - l + 1;
            }
            l--, h++;
        }
    }

    return S.substr(ans_begin_index, ans_length);
}

int main()
{
    string s = "aaaabbaa";
    cout << longestPalindrome(s) << endl;
    return 0;
}