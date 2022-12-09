#include <iostream>
using namespace std;
// practice ---> https://leetcode.com/problems/count-and-say/

// reference --> https://www.youtube.com/watch?v=1YUqtoT9YoE

// recursive approach
string countAndSay_recursive(int n)
{
    if (n == 1)
        return "1";

    string sp = countAndSay_recursive(n - 1); // sp stands for sub problem

    sp += '*';

    int count = 1;
    string ans;

    for (int i = 1; i < sp.size(); i++)
    {
        if (sp[i] != sp[i - 1])
        {
            ans += to_string(count);
            ans += sp[i - 1];

            count = 1;
        }
        else
            count++;
    }

    return ans;
}

// iterative approach
string countAndSay_iterative(int n)
{
    // reference --- https://www.youtube.com/watch?v=1YUqtoT9YoE
    if (n <= 0)
        return "0";

    if (n == 1)
        return "1";

    if (n == 2)
        return "11";

    string s = "11";

    for (int i = 3; i <= n; i++)
    {
        string t = "";
        s += '&'; // adding some random symbol at end to stop checking for same element while counting count-variable
        int count = 1;
        for (int j = 1; j < s.size(); j++)
        {
            if (s[j] != s[j - 1])
            {
                t += to_string(count);
                t += s[j - 1];

                // setting count to 1 for next digit counting
                count = 1;
            }
            else
                count++;
        }
        s = t;
    }
    return s;
}

int main()
{
    cout << countAndSay_recursive(4);

    return 0;
}