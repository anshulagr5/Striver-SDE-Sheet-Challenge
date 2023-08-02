#include <bits/stdc++.h> 
using namespace std;
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

int getMaxWidth(TreeNode<int> *root)
{
    if (!root)
    return 0;
  int ans = 0;
  queue <TreeNode<int> * > q;
  q.push( root);
  while (!q.empty())
   {
    int size = q.size();
    ans=max(ans,size);

    for (int i = 0; i < size; i++) {
     TreeNode<int> * temp = q.front();
      q.pop();
     
      if (temp -> left)
        q.push(temp -> left);
      if (temp -> right)
        q.push(temp -> right);
    }
  }
  return ans;
}
