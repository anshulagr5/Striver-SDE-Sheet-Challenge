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
TreeNode<int>* helper(vector<int>&arr,int i,int j)
{
    if(i>j)return NULL;

    int mid=i + (j-i)/2;

    TreeNode<int>*temp=new TreeNode<int>(arr[mid]);

    temp->left=helper(arr,i,mid-1);
    temp->right=helper(arr,mid+1,j);
    
    return temp;
}
TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    return helper(arr,0,n-1);
}
