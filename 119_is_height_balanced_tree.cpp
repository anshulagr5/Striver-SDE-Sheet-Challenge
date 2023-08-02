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
int helper(BinaryTreeNode<int>*root,bool &ans)
{
    if(ans==false)return 0;
    if(root==NULL)return 0;
    int l=helper(root->left,ans);
    int r=helper(root->right,ans);
    int temp=abs(l-r);
    if(temp>1)ans=false;
    return 1+max(l,r);
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    bool ans=true;
    helper(root,ans);
    return ans;
}
