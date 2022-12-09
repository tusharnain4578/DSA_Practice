#include <iostream>
using namespace std;
// practice --> https://practice.geeksforgeeks.org/problems/palindromic-array-1587115620/1

// GFG school level problem, easier than easy

bool isPalin(int num)
{
    int num_bak = num;

    int rev_num = 0;

    while (num)
    {
        int last_digit = num % 10;

        rev_num = rev_num * 10 + last_digit;

        num /= 10;
    }

    return num_bak == rev_num;
}

int PalinArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        if (!isPalin(a[i]))
            return false;

    return true;
}