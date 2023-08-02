#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool helper(TreeNode<int>*root,TreeNode<int>*p,TreeNode<int>*q,TreeNode<int>*&ans)
{
    if(root==NULL)return false;
    if(root->data==p->data || root->data==q->data){
        ans=root;
        return true;
    }
    bool l=helper(root->left,p,q,ans);
    bool r=helper(root->right,p,q,ans);

    if(l && r){
        ans=root;
        return true;
    }
    else if(l || r)return true;
    return false;

}
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q)
{
   TreeNode<int>*ans=NULL;
   helper(root,p,q,ans);
   return ans;
}
