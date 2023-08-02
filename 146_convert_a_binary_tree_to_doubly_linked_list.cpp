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
void helper(BinaryTreeNode<int>*root,BinaryTreeNode<int>*&ans,BinaryTreeNode<int>*&res){
  if(root==NULL)return;
  helper(root->left,ans,res);
  BinaryTreeNode<int>*temp=new BinaryTreeNode<int>(root->data);
  if(ans==NULL){
     ans=temp; 
     res=temp;
  }
  else{
      ans->right=temp;
      temp->left=ans;
      ans=temp;
  }
  helper(root->right,ans,res);
}
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    BinaryTreeNode<int>*ans=NULL;
    BinaryTreeNode<int>*res=NULL;
    helper(root,ans,res);
    return res;
}
