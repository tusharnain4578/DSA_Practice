#include <iostream>
#include <vector>
using namespace std;
// practice ---> https://www.codingninjas.com/codestudio/problems/make-it-palindrome_3189160

int palindrome(vector<int> A)
{
    int n = A.size();
    int i = 0, j = n - 1, ans = 0;
    long long left = A[0], right = A[n - 1];
    while (i < j)
    {
        // If endpoints are same, we do not megre any indexes.
        if (left == right)
        {
            i++;
            j--;
            left = A[i];
            right = A[j];
        }
        // If Left endpoint is small, we merge two left indexes.
        else if (left < right)
        {
            ans++;
            left += A[i + 1];
            i++;
        }
        // We merge two right indexes.
        else
        {
            ans++;
            right += A[j - 1];
            j--;
        }
    }
    return ans;
}