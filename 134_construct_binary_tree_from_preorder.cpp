#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
TreeNode<int>* helper(int i,int j,vector<int>&preorder)
{
    if(i>j)return NULL;
   
    TreeNode<int>*temp=new TreeNode<int>(preorder[i]);
    if(i==j)return temp;
    int mid=(i+1)+(j-i-1)/2;
    if(preorder[mid]<=temp->data){
        temp->left=helper(i+1,mid,preorder);
        temp->right=helper(mid+1,j,preorder);
    }
    else{
        temp->left=helper(i+1,mid-1,preorder);
        temp->right=helper(mid,j,preorder);
    }
    return temp;

}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    int n=preOrder.size();
    return helper(0,n-1,preOrder);
}
