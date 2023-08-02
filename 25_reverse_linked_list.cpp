#include <bits/stdc++.h>
using namespace std;
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

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    LinkedListNode<int>*p=head;
    LinkedListNode<int>*q=head;
    LinkedListNode<int>*prev=NULL;
    while(p!=NULL)
    {
        q=q->next;
        p->next=prev;
        prev=p;
        p=q;
       
    }
    return prev;
}
