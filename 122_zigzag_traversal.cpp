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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    if(!root)return {};
     vector<int>ans;
     deque<BinaryTreeNode<int>*>dq;
     dq.push_front(root);
     int c=0;
     while(dq.size()!=0)
     {
         int n=dq.size();

         for(int i=0;i<n;i++)
         {
            if(c==1)
            {
             BinaryTreeNode<int>*temp=dq.back();
             if(temp->right)dq.push_front(temp->right);
             if(temp->left)dq.push_front(temp->left);
               ans.push_back(temp->data);
               dq.pop_back();
            }
            else{
             BinaryTreeNode<int>*temp=dq.front();
             if(temp->left)dq.push_back(temp->left);
             if(temp->right)dq.push_back(temp->right);
               ans.push_back(temp->data);
               dq.pop_front();
            }

         }
         if(c==0)c=1;
         else c=0;
            
     }
     return ans;
}
