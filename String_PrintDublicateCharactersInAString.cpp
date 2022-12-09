#include <iostream>
#include <unordered_map>
using namespace std;

void printDups(string str)
{
    unordered_map<char, int> map;

    int n = str.size();

    for (int i = 0; i < n; i++)
        map[str[i]]++;

    for (auto it : map)
        if (it.second > 1)
            cout << it.first << ", count = " << it.second << endl;
}

int main()
{
    string str = "test string";
    printDups(str);
    return 0;
}