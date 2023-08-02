#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

bool isPalindrome(LinkedListNode<int> *head) {
    if(head==NULL || head->next==NULL)return 1;
   LinkedListNode<int>*p=head;
   LinkedListNode<int>*q=head;
    int count=1;
    while (q->next != NULL) {
      q = q->next;
      count++;
    }
    int mid=count/2 ;
    LinkedListNode<int>*prev=NULL;
    q=head;
    while(q!=NULL && mid--){
        LinkedListNode<int>*temp=q->next;
        q->next=prev;
        prev=q;
        q=temp;
    }
    if(count%2){
        q=q->next;
    }
    while(prev!=NULL && q!=NULL){
        if(prev->data!=q->data)return 0;
        prev=prev->next;
        q=q->next;
    }
    return 1;
}
