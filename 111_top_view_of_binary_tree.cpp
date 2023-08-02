#include <bits/stdc++.h> 
using namespace std;
/************************************************************

    Following is the TreeNode class structure:

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
void helper(TreeNode<int>*root,map<int,pair<int,int>>&mp,int x,int y)
{
    if(root==NULL)return;
    if(mp.find(x)!=mp.end())
    {
        if(y<mp[x].first)
        {
           mp[x].first=y;
           mp[x].second=root->val;
        }
    }
    else{
        mp[x]={y,root->val};
    }
     helper(root->left,mp,x-1,y+1);
     helper(root->right,mp,x+1,y+1);
}

vector<int> getTopView(TreeNode<int> *root) {
        map<int,pair<int,int>>mp;
        vector<int>ans;

        helper(root,mp,0,0);
        
        for(auto it : mp) {
            ans.push_back(it.second.second); 
        }
        return ans;  
}
