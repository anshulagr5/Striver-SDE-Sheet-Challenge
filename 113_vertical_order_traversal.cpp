#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/
void helper(TreeNode<int>*root,map<pair<int,int>,vector<int>>&mp,int x,int y)
{
    if(root==NULL)return;
        mp[{x,y}].push_back(root->data);

    helper(root->left,mp,x-1,y+1);
    helper(root->right,mp,x+1,y+1);
}
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    map<pair<int,int>,vector<int>>mp;
    helper(root,mp,0,0);
    vector<int>ans;

    for(auto it:mp)
    {
        for(auto c:it.second)
        {
            ans.push_back(c);
        }
    }
    return ans;
    
}
