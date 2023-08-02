#include <bits/stdc++.h> 
using namespace std;
/*************************************************************
 
    Following is the Binary Tree node structure.

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
void helper(BinaryTreeNode<int>*root,map<int,pair<int,int>>&mp,int x,int y)
{
    if(root==NULL)return;
    if(mp.find(x)!=mp.end())
    {
        if(y>=mp[x].first)
        {
           mp[x].first=y;
           mp[x].second=root->data;
        }
    }
    else{
        mp[x]={y,root->data};
    }
    helper(root->left,mp,x-1,y+1);
     helper(root->right,mp,x+1,y+1);
}

vector<int> bottomView(BinaryTreeNode<int> * root){
        map<int,pair<int,int>>mp;
        vector<int>ans;

        helper(root,mp,0,0);
        
        for(auto it : mp) {
            ans.push_back(it.second.second); 
        }
        return ans;  
}


