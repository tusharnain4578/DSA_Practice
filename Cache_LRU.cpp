#include <iostream>
#include <unordered_map>
using namespace std;

class LRU_Cache
{
    class Node
    {
    public:
        int key, val;
        Node *next, *prev;

        Node(int key, int val) : key(key), val(val), next(NULL), prev(NULL) {}
    };

    Node *head, *tail;
    int capacity;
    unordered_map<int, Node *> mp;

public:
    LRU_Cache(int capacity) : capacity(capacity),
                              head(new Node(-1, -1)), tail(new Node(-1, -1))
    {
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node *t)
    {
        if (!t)
            return;
        t->next = head->next;
        t->next->prev = t;
        head->next = t;
        t->prev = head;
    }

    void deleteNode(Node *t)
    {
        if (!t)
            return;
        t->prev->next = t->next;
        t->next->prev = t->prev;
    }

    int get(int _key)
    {
        if (mp.find(_key) == mp.end())
            return -1;

        Node *t = mp[_key];
        mp.erase(_key);
        deleteNode(t);
        addNode(t);
        mp[_key] = t;
        return t->val;
    }

    void put(int _key, int _value)
    {
        if (mp.find(_key) != mp.end())
        {
            deleteNode(mp[_key]);
            mp.erase(_key);
        }

        if (mp.size() == capacity)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new Node(_key, _value));
        mp[_key] = head->next;
    }
};