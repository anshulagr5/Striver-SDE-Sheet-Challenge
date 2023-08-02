#include <bits/stdc++.h> 
/********************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode {
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
    
********************************************************************/
void helper(BinaryTreeNode < int > * root,vector<string>&ans,string temp)
{
    if(root==NULL)return;
    temp+=to_string(root->data);
    if(root->left==NULL && root->right==NULL){
        ans.push_back(temp);
        return;
    }
   
    helper(root->left,ans,temp+" ");
    helper(root->right,ans,temp+" ");
    temp.pop_back();
}
vector < string > allRootToLeaf(BinaryTreeNode < int > * root) {
    if(!root)return{};
    vector<string>ans;
    helper(root,ans,"");
    return ans;
}
