#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void find(TreeNode<int>*root,int x,int &ans){
    if(root==NULL)return;
    if(root->val==x){
        ans=x;
        return;
    }
    if(root->val>x)find(root->left,x,ans);
    if( root->val < x) {
      ans = max(ans, root->val);
      find(root->right, x, ans);
    }
}
int floorInBST(TreeNode<int> * root, int X)
{
    int ans=-1;
    find(root,X,ans);
    return ans;
}
