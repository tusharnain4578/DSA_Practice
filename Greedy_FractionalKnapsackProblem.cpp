#include <iostream>
#include <iomanip> //for setprecision funtion
#include <algorithm>
using namespace std;

struct Item
{
    int value;
    int weight;
};

bool comp(Item a, Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;

    return r1 > r2;
}

double fractionalKnapsack(int W, Item arr[], int n)
{
    // reference ---> https://www.youtube.com/watch?v=F_DDzYnxO14
    sort(arr, arr + n, comp);

    int current_weight = 0;
    double final_value = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i].weight + current_weight <= W)
        {
            current_weight += arr[i].weight;
            final_value += arr[i].value;
        }
        else
        {
            int remainig_weight = W - current_weight;
            final_value += ((double)arr[i].value / (double)arr[i].weight) * (double)remainig_weight;
            break;
        }
    }
    return final_value;
}

int main()
{
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(2) << fixed;
    while (t--)
    {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].value >> arr[i].weight;
        }

        cout << fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}