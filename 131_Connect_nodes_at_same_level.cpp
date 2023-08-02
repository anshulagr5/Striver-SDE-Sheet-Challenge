#include <bits/stdc++.h> 
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode< int > *root) {
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    
    while(!q.empty())
    {
        int n=q.size();
       BinaryTreeNode<int>*prev=q.front();
        for(int i=0;i<n;i++)
        {
          BinaryTreeNode<int> *temp = q.front();
          if (i != 0) {
            prev->next = temp;
            prev = temp;
          }
          q.pop();
          if(temp->left)q.push(temp->left);
          if(temp->right)q.push(temp->right);
        }

    }
}
