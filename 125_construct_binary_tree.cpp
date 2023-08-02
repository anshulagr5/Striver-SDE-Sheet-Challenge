#include <bits/stdc++.h> 
using namespace std;
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int> * constructTree(vector < int > & preorder, int preStart, int preEnd, vector 
 < int > & inorder, int inStart, int inEnd, map < int, int > & mp) 
 {
  if (preStart > preEnd || inStart > inEnd) return NULL;

  TreeNode<int> * root = new TreeNode<int>(preorder[preStart]);
  int elem = mp[root -> data];
  int nElem = elem - inStart;

  root -> left = constructTree(preorder, preStart + 1, preStart + nElem, inorder,
  inStart, elem - 1, mp);
  root -> right = constructTree(preorder, preStart + nElem + 1, preEnd, inorder, 
  elem + 1, inEnd, mp);

  return root;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
     map<int,int>mp;
     int n=inorder.size();
     for(int i=0;i<n;i++)
     mp[inorder[i]]=i;
     TreeNode<int>*ans=constructTree(preorder,0,n-1,inorder,0,n-1,mp);
     return ans;
}
