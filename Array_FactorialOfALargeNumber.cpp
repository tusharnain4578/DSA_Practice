#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// practoce --> https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1
vector<int> factorial(int N)
{
    // reference ---> https://www.youtube.com/watch?v=Rv4uNb2QX2w
    vector<int> ans{1};

    for (int i = 2; i <= N; i++)
    {
        int carry = 0;
        for (int j = 0; j < ans.size(); j++)
        {
            int prod = ans[j] * i + carry;
            ans[j] = prod % 10;
            carry = prod / 10;
        }
        while (carry > 0)
        {
            ans.push_back(carry % 10);
            carry /= 10;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int num = 10;
    vector<int> fact = factorial(num);
    cout << "There are " << fact.size() << " digits in the factorial of " << num << "." << endl
         << "The Factorial -> " << endl;
    for (auto &&i : fact)
    {
        cout << i;
    }

    return 0;
}