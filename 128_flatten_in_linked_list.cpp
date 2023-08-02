#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure.

    template <typename T>
    class TreeNode {
        public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void helper(TreeNode<int>*root,TreeNode<int>*&prev)
{
    if(!root)return;
    helper(root->right,prev);
    helper(root->left,prev);
    root->right=prev;
    root->left=NULL;
    prev=root;
}
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    TreeNode<int>*prev=NULL;
    helper(root,prev);
    return prev;
}
