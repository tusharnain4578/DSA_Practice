#include <iostream>
#include <vector>
using namespace std;

vector<int> rabinKarp(string &str, string &pat)
{

    vector<int> ans;

    int str_size = str.size();
    int pat_size = pat.size();
    int d = 128; // multiplier
    int q = 131; // prime number for modulo operation

    int h = 1;
    for (int i = 0; i < pat_size - 1; i++)
        h = (h * d) % q;

    int str_traversal_hash = 0, pattern_hash = 0;

    for (int i = 0; i < pat_size; i++)
    {
        str_traversal_hash = (str_traversal_hash * d + str[i]) % q;
        pattern_hash = (pattern_hash * d + pat[i]) % q;
    }

    for (int i = 0; i <= str_size - pat_size; i++)
    {
        if (str_traversal_hash == pattern_hash)
        {
            int k = 0;
            while (k < pat_size)
            {
                if (pat[k] != str[i + k])
                    break;
                k++;
            }
            if (k == pat_size)
                ans.push_back(i);
        }

        if (i < str_size - pat_size)
        {
            str_traversal_hash = (d * (str_traversal_hash - str[i] * h) + str[i + pat_size]) % q;

            if (str_traversal_hash < 0)
                str_traversal_hash += q;
        }
    }

    return ans;
}

int main()
{
    string text = "ABABABABCABABDAABABCABABBACDABABCABABABABCABAB";
    string pat = "ABABCABAB";

    vector<int> res = rabinKarp(text, pat);

    for (int &i : res)
        cout << i << endl;

    return 0;
}