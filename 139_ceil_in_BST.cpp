#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/
void find(BinaryTreeNode<int> *root, int x,int &ans)
{
    if(root==NULL)return;
    if(root->data==x){
         ans=root->data;
         return;
    }
    if(root->data>x){
        ans=min(root->data,ans);
        find(root->left,x,ans);
    }
    if(root->data<x){
        find(root->right,x,ans);
    }
}
int findCeil(BinaryTreeNode<int> *node, int x){
    int ans=INT_MAX;
    find(node,x,ans);
    return (ans==INT_MAX)?-1:ans;
}
