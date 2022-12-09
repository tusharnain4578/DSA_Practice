#include <iostream>
#include <unordered_map>
using namespace std;

struct Node
{
    int key, value, frequency;
    Node *next, *prev;
    Node(int key, int value) : key(key), value(value), frequency(1) {}
};

struct List
{
    Node *head, *tail;
    int size;

    List() : head(new Node(-1, -1)), tail(new Node(-1, -1))
    {
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node *t)
    {
        t->next = head->next;
        t->prev = head;
        head->next = t;
        t->next->prev = t;
        size++;
    }

    void remove(Node *t)
    {
        t->prev->next = t->next;
        t->next->prev = t->prev;
        size--;
    }
};

class LFUCache
{
    unordered_map<int, Node *> key_node;
    unordered_map<int, List *> frequency_list_map;
    int minimum_frequency, capacity, current_size;

public:
    LFUCache(int capacity) : capacity(capacity)
    {
        minimum_frequency = current_size = 0;
    }

    void updateFrequencyList(Node *t)
    {
        frequency_list_map[t->frequency]->remove(t);

        if (frequency_list_map[t->frequency]->size == 0 && t->frequency == minimum_frequency)
            minimum_frequency++;

        List *target_list = new List;
        if (frequency_list_map.find(t->frequency + 1) != frequency_list_map.end())
            target_list = frequency_list_map[t->frequency + 1]; //+1 for new freq list

        t->frequency++;
        target_list->addFront(t);

        if (target_list->size >= 1)
            frequency_list_map[t->frequency] = target_list;
    }

    int get(int key)
    {
        if (key_node.find(key) != key_node.end())
        {
            int res = key_node[key]->value;
            updateFrequencyList(key_node[key]);
            return res;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (capacity == 0)
            return;

        if (key_node.find(key) != key_node.end())
        {
            key_node[key]->value = value;
            updateFrequencyList(key_node[key]);
            return;
        }

        if (current_size == capacity)
        {
            key_node.erase(frequency_list_map[minimum_frequency]->tail->prev->key);
            frequency_list_map[minimum_frequency]->remove(frequency_list_map[minimum_frequency]->tail->prev);
            current_size--; // this size-decrement and the below size-increment are gonna run eventually, so if you want you can just remove both, no difference
        }

        minimum_frequency = 1; // New node will always positioned at freq 1 initially

        List *target_list = new List;

        if (frequency_list_map.find(minimum_frequency) != frequency_list_map.end())
            target_list = frequency_list_map[minimum_frequency];

        Node *new_node = new Node(key, value);

        key_node[key] = new_node;
        target_list->addFront(new_node);

        if (target_list->size >= 1)
            frequency_list_map[minimum_frequency] = target_list;

        current_size++;
    }
};