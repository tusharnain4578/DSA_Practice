#include <iostream>
using namespace std;

int myAtoi(string s)
{
    int n = s.size();
    int sign = 1;
    int i = 0;

    long long ans = 0;

    while (s[i] == ' ')
        i++;

    if (s[i] == '-' || s[i] == '+')
        sign = 1 - 2 * (s[i++] == '-');

    while (i < n)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            ans = ans * 10 + s[i] - '0'; // make sure to calculate ans first in the loop

            if (ans > INT_MAX)
            {
                if (sign == 1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }
        }
        else
            break;
        i++;
    }
    return (int)(ans * sign);
}

int main()
{
    string s1 = "42";
    string s2 = "   -42";
    string s3 = "4193 with words";
    string s4 = "21474836460";
    // cout << "-" << myAtoi(s1) << "-" << endl;
    // cout << "-" << myAtoi(s2) << "-" << endl;
    // cout << "-" << myAtoi(s3) << "-" << endl;
    cout << myAtoi(s4) << endl;

    return 0;
}