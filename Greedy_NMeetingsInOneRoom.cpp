#include <iostream>
#include <algorithm>
using namespace std;

struct meeting
{
    int start, end;
    void set(int _start, int _end)
    {
        start = _start;
        end = _end;
    }
};

// custom comparator
bool comp(struct meeting a, meeting b)
{
    if (a.end < b.end)
        return true;
    else
        return false;
}

int maxMeetings(int start[], int end[], int n)
{
    // reference ---> https://www.youtube.com/watch?v=II6ziNnub1Q
    struct meeting meet[n];
    for (int i = 0; i < n; i++)
        meet[i].set(start[i], end[i]);

    sort(meet, meet + n, comp);

    int count = 0;
    int limit = -1;

    for (struct meeting const &i : meet)
    {
        if (i.start > limit)
        {
            count++;
            limit = i.end;
        }
    }

    return count;
}

int main()
{
    int start[]{1, 3, 0, 5, 8, 5};
    int end[]{2, 4, 6, 7, 9, 9};

    int a = maxMeetings(start, end, 6);
    cout << a << endl;
    return 0;
}

// for (int i = 0; i < n; i++)
//     {
//         cout << meet[i].start << " " << meet[i].end << endl;
//     }