#include <iostream>
using namespace std;

bool checkValid(string s1, string s2, string, string result)
{
    int l1 = s1.size(), l2 = s2.size(), lr = result.size();

    int i = 0, j = 0, k = 0; // itr for s1, s2, result string

    while (k < lr)
    {
        if (i < l1 and s1[i] == result[k])
            i++;
        else if (j < l2 and s2[j] == result[k])
            j++;
        else
        {
            return false;
        }

        k++;
    }

    // after accessing all characters of result
    // if either first or second has some characters left
    if (i < l1 or j < l2)
        return false;

    return true;
}