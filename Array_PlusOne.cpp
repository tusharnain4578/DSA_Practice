#include <iostream>
#include <vector>
using namespace std;
// practice --> https://leetcode.com/problems/plus-one/

vector<int> plusOne(vector<int> &digits)
{
    int n = digits.size();

    // if the last digit is not 9, then just simply increment the last digit and return
    if (digits[n - 1] != 9)
    {
        digits[n - 1]++;
        return digits;
    }

    // this will change all the 9 to 0, if there's no 9 somewhere in between, we just simiple inncrement that and return
    // like 12999, the following while loop will first convert all 9 to 0 and then 2 to 3, and return 13000
    int i = n - 1;
    while (i >= 0)
    {
        if (digits[i] == 9)
            digits[i--] = 0;
        else
        {
            digits[i]++;
            return digits;
        }
    }

    // this mean that the all digits were 9999 like, and the above while loop changes it to 0000 and now all we have to do is to put 1 in the beginning and return it
    digits[0] = 1;
    digits.push_back(0);
    return digits;
}