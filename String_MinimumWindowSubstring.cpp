#include <iostream>
#include <unordered_map>
using namespace std;
// practice ---> https://leetcode.com/problems/minimum-window-substring/

// LC Hard ---- 🔥

// reference --> https://www.youtube.com/watch?v=e1HlptlipB0

string minWindow(string s, string t)
{
    int s_length = s.size(), t_length = t.size();

    string ans = "";

    unordered_map<char, int> t_map, s_map;

    for (auto const &ch : t)
        t_map[ch]++;

    int mash_count = 0, desired_mash_count = t_length;

    int i = -1, j = -1;
    // i if for starting, j for ending

    while (true)
    {

        // flags for breaking loop
        bool f1 = false, f2 = false;

        // acquire
        while (j < s_length - 1 and mash_count < desired_mash_count)
        {
            j++;

            char ch = s[j];
            s_map[ch]++;

            if (s_map[ch] <= t_map[ch])
                mash_count++;

            f1 = true;
        }

        // release and collect answer
        while (i < j and mash_count == desired_mash_count)
        {
            string this_ans = s.substr(i + 1, j - i);
            if (ans.size() == 0 or this_ans.size() < ans.size())
                ans = this_ans;

            i++;

            char ch = s[i];

            if (s_map[ch] >= 1)
                s_map[ch]--;

            if (s_map[ch] < t_map[ch])
                mash_count--;

            f2 = true;
        }

        if (f1 == false and f2 == false)
            break;
    }

    return ans;
}

// driver
int main()
{
    string s1 = "abc", t1 = "b";
    string s2 = "ADOBECODEBANC", t2 = "ABC";
    cout << minWindow(s1, t1) << endl;
    cout << "_____" << endl;
    cout << minWindow(s2, t2) << endl;

    return 0;
}