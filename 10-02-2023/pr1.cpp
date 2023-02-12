// Date:- 10-02-2023  Author:- Niranjan Kumar Q:- implementation of binary tree.

#include <bits/stdc++.h>
using namespace std;

class Tree
{
public:
    int data;
    Tree *left;
    Tree *right;

    Tree(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void insert(Tree* &root, int data)
{
    
    if (root == NULL)
    {
        Tree *node = new Tree(data);
        root = node;
        return;
    }
    if (data < root->data)
    {
        if (root->left == NULL)
        {
            Tree *node = new Tree(data);
            root->left = node;
            return;
        }
        else
        {
            insert(root->left, data);
        }
    }
    else
    {
        if (root->right == NULL)
        {
            Tree *node = new Tree(data);
            root->right = node;
            return;
        }
        else
        {
            insert(root->right, data);
        }
    }
}

Tree* successor(Tree* root,int data)
{
    if(root== NULL) return NULL;
    if(root->left == NULL) return root;

    successor(root->left,data);
     

}
void deletion(Tree* &root,int data,Tree* &prev)
{

    if(root == NULL) return ;

    if(root->data == data)
    {
        if(root->left == NULL && root->right == NULL)
        {
            if(prev->left == root)
            prev->left = NULL;
            else
            prev->right = NULL;

            return;
        }
        else if(root->left == NULL || root->right == NULL)
        {
            if(prev->left == root)
            {
                if(root->left != NULL)
                {
                    prev->left = root->left;
                    return;
                }
                else{
                    prev->left = root->right;
                    return;
                }
            }
            else
            {
                if(root->left != NULL)
                {
                    prev->right = root->left;
                    return;
                }
                else{
                    prev->right = root->right;
                    return;
                }
            }
        }
        else{
            Tree*succes = successor(root->right,data);
            swap(root->data,succes->data);
            deletion(root, data,prev);
            return;
        }
    }


    deletion(root->left,data,root);
    deletion(root->right,data,root);
}

void inorder(Tree *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{

    Tree *root = NULL;

    insert(root, 10);
    insert(root, 20);
    insert(root, 50);
    insert(root, 70);
    insert(root, 40);
    insert(root, 80);
    insert(root, 60);

    inorder(root);
    cout<<endl;
    Tree* prev = NULL;
    deletion(root,50,prev);
    inorder(root);

    return 0;
}