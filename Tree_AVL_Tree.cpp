#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;
    int height;
    static node *newnode(int x)
    {
        node *newnode = new node;
        newnode->data = x;
        newnode->left = newnode->right = NULL;
        newnode->height = 0;
        return newnode;
    }
};
int height(node *p)
{
    if (p)
        return p->height;
    return -1;
}
node *LLRotation(node *p)
{
    node *x = p->left;
    node *t = x->right;

    p->left = t;
    x->right = p;

    p->height = max(height(p->right), height(p->left)) + 1;
    x->height = max(height(x->right), height(x->left)) + 1;

    return x;
}
node *RRRotation(node *p)
{
    node *x = p->right;
    node *t = x->left;

    p->right = t;
    x->left = p;
    p->height = max(height(p->right), height(p->left)) + 1;
    x->height = max(height(x->right), height(x->left)) + 1;
    return x;
}

int bf(node *p)
{
    if (p)
        return height(p->left) - height(p->right);
    return -1;
}

class AVL
{
    node *root;
    node *add(node *p, int x)
    {
        if (p == NULL)
            return node::newnode(x);

        if (x < p->data)
            p->left = add(p->left, x);
        else if (x > p->data)
            p->right = add(p->right, x);

        p->height = max(height(p->right), height(p->left)) + 1;
        int balanceFactor = bf(p);
        if (balanceFactor == 2 && bf(p->left) == 1)
            return LLRotation(p);
        if (balanceFactor == -2 && bf(p->right) == -1)
            return RRRotation(p);
        if (balanceFactor == 2 && bf(p->left) == -1)
        {
            p->left = RRRotation(p->left);
            return LLRotation(p);
        }
        if (balanceFactor == -2 && bf(p->right) == 1)
        {
            p->right = LLRotation(p->right);
            return RRRotation(p);
        }
        return p;
    }
    void inorderTraversal(node *p)
    {
        if (p)
        {
            inorderTraversal(p->left);
            cout << p->data << " ";
            inorderTraversal(p->right);
        }
    }

public:
    AVL() { root = NULL; }
    void insert(int x)
    {
        root = add(root, x);
    }
    void inorderDisplay()
    {
        inorderTraversal(root);
    }
    node *getRoot() { return root; }
};

//Level Order Traversal Print
void printLevelOrder(node *p)
{
    if (p)
    {
        queue<node *> q;
        q.push(p);
        while (!q.empty())
        {
            node *node = q.front();
            q.pop();
            cout << node->data << " ";
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }
}

// Level Order Traversal Return in vector<vector<int>>
vector<vector<int>> levelOrder(node *p)
{
    vector<vector<int>> ans;
    queue<node *> q;
    q.push(p);
    while (!q.empty())
    {
        vector<int> level;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            node *node = q.front();
            q.pop();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
}

//Left View of Binary Tree
void LeftView(node *p, int level)
{
    if (p)
    {
        static int dsSize = 0;
        if (dsSize == level)
        {
            cout << p->data << endl;
            dsSize++;
        }
        LeftView(p->right, level + 1);
        LeftView(p->left, level + 1);
        //Just flip these above recursions for right view
    }
}

//Height of Binary Tree
int heightBinaryTree(node *p)
{
    if (p)
    {
        int lh = heightBinaryTree(p->left);
        int rh = heightBinaryTree(p->right);
        return ((lh > rh) ? lh : rh) + 1;
    }
    return -1;
}

//Mirror of Binary Tree
//---swap node function

void mirror(node *p)
{
    if (p)
    {
        mirror(p->left);
        mirror(p->right);
        swap(p->left, p->right);
    }
}



int main()
{
    AVL a;
    // a.insert(5);
    // a.insert(19);
    // a.insert(20);
    // a.insert(15);
    // a.insert(23);
    // a.insert(1);
    // a.insert(13);

    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a.insert(x);
    }

    vector<vector<int>> vec = levelOrder(a.getRoot());

    for(auto it: vec){
        for(auto jt : it)
            cout<<jt<<" ";
            cout<<endl;
    }

    // a.inorderDisplay();
    levelOrder(a.getRoot());

    return 0;
}
