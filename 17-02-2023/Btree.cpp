// Date:- 17-02-2023  Author:- Niranjan Kumar  Q:- Btree implementation

#include<iostream>
using namespace std;


class BtreeNode
{
    int* keys;  // keys is aray of keys

    // minimum degree
    int t;

    //an array of child pointers
    BtreeNode** c;
    int n;
    // true if node is leaf else false
    bool leaf;

    public:
    BtreeNode(int _t,bool _leaf);

    void insertNonFull(int k);

    void splitChild(int i,BtreeNode* y);

    void traverse();


    BtreeNode* search(int k);

    friend class Btree;
};


class Btree{
    BtreeNode* root;
    int t;

    public:

    // constructor
    Btree(int _t)
    {
        root = NULL;
        t = _t;
    }

    void traverse()
    {
        if(root != NULL) 
        root->traverse();
    }

    BtreeNode* search(int k)
    {
        return (root == NULL) ? NULL : root->search(k);
    }


    void insert(int k);
};

BtreeNode:: BtreeNode(int _t,bool leaf)
{
    t = _t;

    leaf = leaf;

    keys = new int[2*t -1];
    c = new BtreeNode*[2*t];

    n =0;
}

void BtreeNode :: traverse()
{
    int i;
    for(int i =0;i<n;i++)
    {
        if(leaf == false)
        c[i]->traverse();
        cout<<" "<<keys[i];
    }

    if(leaf == false)
    c[i]->traverse();
}

BtreeNode* BtreeNode::search(int k)
{
    int i =0;
    while(i<n && k>keys[i])
    i++;

    if(keys[i] == k) return this;

    if(leaf == true) return NULL;

    return c[i]->search(k);
}

void Btree::insert(int k)
{
    if(root == NULL)
    {
        root = new BtreeNode(t,true);
        root->keys[0] = k;
        root->n = 1;
    }
    else{
        if(root->n == 2*t-1)
        {
            BtreeNode *s = new BtreeNode(t,false);

            s->c[0] = root;
            s->splitChild(0,root);

            int i =0;

            if(s->keys[0] <  k)
            i++;
            s->c[i]->insertNonFull(k);

            root = s;

        }
        else
        root->insertNonFull(k);
    }
}

void BtreeNode :: insertNonFull(int k)
{
     int i = n-1;

     if(leaf == true)
     {
        while(i>=0 && keys[i] > k)
        {
            keys[i+1] = keys[i];
            i--;
        }

        keys[i+1] = k;
        n = n+1;
     }

     else
     {
        while(i>=0 && keys[i] > k)
        i--;

        if(c[i+1]->n == 2*t-1)
        {
            splitChild(i+1,c[i+1]);

            if(keys[i+1] < k)
            i++;
        }
        c[i+1]->insertNonFull(k);
     }
}

void BtreeNode::splitChild(int i,BtreeNode* y)
{
    BtreeNode*z  = new BtreeNode(y->t,y->leaf);
    z->n = t-1;

    for(int j =0;j<t-1;j++)
    z->keys[j] = y->keys[j+t];


    if(y->leaf == false)
    {
        for(int j =0;j<t;j++)
        z->c[j] = y->c[j+t];
    }

    y->n = t-1;

    for(int j = n;j>= i+1;j--)
    {
        c[j+1] = c[j];
    }

    c[i+1] = z;

    for(int j = n-1;j>=i;j--)
    {
        keys[j+1] = keys[j];
    }

    keys[i] = y->keys[t-1];

    n = n+1;
}

int main()
{
    Btree* root = new Btree(4);
    root->insert(10);
    root->insert(20);
    root->insert(30);
    root->insert(40);
    root->insert(50);

    root->traverse();
    return 0;
}