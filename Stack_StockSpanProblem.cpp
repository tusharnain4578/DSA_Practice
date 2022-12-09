#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// practice --> https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
vector<int> calculateSpan(int price[], int n)
{
    vector<int> ans;
    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++)
    {
        int freq = 1;
        while (!st.empty() and st.top().first <= price[i])
        {
            freq += st.top().second;
            st.pop();
        }
        st.push(make_pair(price[i], freq));
        ans.push_back(freq);
    }
    return ans;
}

int main()
{
    int n = 7;
    int price[]{100, 80, 60, 70, 60, 75, 85};

    vector<int> ans = calculateSpan(price, n);
    for (int &i : ans)
        cout << i << " ";

    return 0;
}