#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

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
void helper(TreeNode<int>*root,int level, vector<int>&res)
{
    if(root==NULL)return;
    if(level>res.size())res.push_back(root->data);
    helper(root->left,level+1,res);
    helper(root->right,level+1,res);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int>ans;
    helper(root,1,ans);
    return ans;
}
