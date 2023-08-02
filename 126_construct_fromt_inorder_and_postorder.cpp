#include<bits/stdc++.h>
using namespace std;

/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
 
TreeNode<int>* find(vector<int>&postOrder,int poststart,int postend,
vector<int>&inOrder,int instart,int inend,map<int,int>&mp)
{
     if(poststart>postend || instart>inend)return NULL;
     TreeNode<int>*temp=new TreeNode<int>(postOrder[postend]);
     int sizeL=mp[postOrder[postend]] - instart;
     int sizeR=inend - mp[postOrder[postend]];
     temp->left=find(postOrder,poststart,poststart+sizeL-1,inOrder,instart,instart+sizeL-1,mp);
     temp->right=find(postOrder,poststart+sizeL,postend-1,inOrder,instart+sizeL+1,inend,mp);
     return temp;
}
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	int n=postOrder.size();
     map<int,int>mp;
     for(int i=0;i<n;i++)mp[inOrder[i]]=i;

     TreeNode<int>*ans=find(postOrder,0,n-1,inOrder,0,n-1,mp);
     return ans;
}
