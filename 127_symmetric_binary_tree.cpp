#include <bits/stdc++.h> 
// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
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
***************/
bool check(BinaryTreeNode<int>* root1,BinaryTreeNode<int>* root2)
{
    if(root1==NULL && root2==NULL)return true;
    if(!root1 || !root2) return false;
    if(root1->data != root2->data)return false;
    bool l=check(root1->left,root2->right);
    bool r=check(root1->right,root2->left);
    if(!l || !r)return false;
    return true;
}
bool isSymmetric(BinaryTreeNode<int>* root) {
   if(!root)return true;
   bool ans=check(root->left,root->right);
   return ans;
}
