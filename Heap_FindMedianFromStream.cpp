#include <iostream>
#include <queue>
using namespace std;

// practice --> https://leetcode.com/problems/find-median-from-data-stream/
class MedianFinder
{
    // reference ---> https://www.youtube.com/watch?v=cjQNm2eS6Lw

    priority_queue<int> max_heap;                            // hold left side elements
    priority_queue<int, vector<int>, greater<int>> min_heap; // holds right side elements
public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (max_heap.empty())
        {
            max_heap.push(num);
        }
        else if (max_heap.size() > min_heap.size())
        {
            if (num < max_heap.top())
            {
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(num);
            }
            else
            {
                min_heap.push(num);
            }
        }
        else
        {
            if (num < max_heap.top())
            {
                max_heap.push(num);
            }
            else
            {
                min_heap.push(num);
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
        }
    }

    double findMedian()
    {
        if (max_heap.size() == min_heap.size())
        {
            return double(max_heap.top() + min_heap.top()) / 2.0;
        }
        else
        {
            return max_heap.top();
        }
    }
};