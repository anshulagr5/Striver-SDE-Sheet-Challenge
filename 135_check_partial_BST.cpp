#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

bool validateBST(BinaryTreeNode<int> *root) {
    if(root==NULL)return true;
    if(root->left==NULL && root->right==NULL)return true;
    if(root->left!=NULL && root->left->data>root->data)return false;
    if(root->right!=NULL && root->right->data<root->data)return false;
    bool l=validateBST(root->left);
    bool r=validateBST(root->right);
    if(!l || !r)return false;
    return true;
}
