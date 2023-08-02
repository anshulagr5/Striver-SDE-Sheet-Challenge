#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/
void helper(BinaryTreeNode<int>*root,vector<int>&pre,vector<int>&ino,vector<int>&post)
{
    if(root==NULL)return;
    pre.push_back(root->data);
    helper(root->left,pre,ino,post);
    ino.push_back(root->data);
    helper(root->right,pre,ino,post);
    post.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<int>preorder;
    vector<int>inorder;
    vector<int>postorder;

    vector<vector<int>>ans;
    helper(root,preorder,inorder,postorder);
    
    ans.push_back(inorder);
    ans.push_back(preorder);
    ans.push_back(postorder);
    return ans;
}
