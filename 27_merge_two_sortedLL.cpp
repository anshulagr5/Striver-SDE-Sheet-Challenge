#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first==NULL)return second;
    if(second==NULL)return first;
    Node<int>*p=NULL;
    Node<int>*head=NULL;
    if (first->data <= second->data) {
        head=first;
      p=first;
      first=first->next;
    }
    else{
        head=second;
      p=second;
      second=second->next;
    }
    while(first!=NULL && second!=NULL)
    {
        if(first->data<=second->data)
        {
            p->next=first;
            p=first;
            first=first->next;

        }
        else{
            p->next=second;
            p=second;
            second=second->next;
        }
    }
    if (first != NULL) {
      p->next = first;
      return head;
    }
    p->next=second;
    return head;

    
}
