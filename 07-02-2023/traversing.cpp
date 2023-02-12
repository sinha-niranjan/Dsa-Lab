// Date:- 07-02-2023  Author:- Niranjan Kumar  Q:- preorder,inorder and postorder

#include <bits/stdc++.h>
using namespace std;

class Tree{
public:
    int data;
    Tree* left;
    Tree* right;
    
     
    Tree(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;

    }
};

void inorder(Tree* root)
{
    if(root == NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Tree* root)
{
    if(root == NULL) return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(Tree* root)
{
    if(root == NULL) return;

    postorder(root->right);
    postorder(root->left);
    cout<<root->data<<" ";
}

Tree* create() 
{

    cout<<"Enter the data for your node : ";
    int data ; cin>>data;
    if(data == -1) return NULL;
    Tree* root = new Tree(data);
    // cout<<"if You want to enter a node in left side of "<<data<<" than enter 1 else 0 for no input : ";
    // int left ; cin>>left;
    cout<<"enter the data for left side of "<<data;
    root->left = create();
    cout << "enter the data for right side of " << data ;
    root->right = create();
    return root;
}

int main()
{

    Tree* root = create();

    // root->left = new Tree(20);
    // root->right = new Tree(39);

    // root->left->left = new Tree(40);
    // root->left->right = new Tree(50);
    // root->right->left = new Tree(60);
 

    cout<<"Inorder of Tree is : ";
    inorder(root);
    cout<<endl;
    cout<<"Preorder of Tree is : ";
    preorder(root);
    cout<<endl;
    cout<<"Postorder of Tree is : ";
    postorder(root);
    cout<<endl;

   return 0;
}