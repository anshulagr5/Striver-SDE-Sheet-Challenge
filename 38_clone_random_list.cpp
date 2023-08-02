#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{

    LinkedListNode<int>*temp=head;
    while(temp!=NULL)
    {
        LinkedListNode<int> *creat=new LinkedListNode<int>(temp->data); 
        creat->next=temp->next;
        temp->next=creat;
        temp=temp->next->next;
    }

    LinkedListNode<int>*it=head;
    while(it!=NULL)
    {
        if(it->random!=NULL)it->next->random=it->random->next;
        else it->next->random=NULL;
        it=it->next->next;
    }

    it=head;
    LinkedListNode<int> *result=new LinkedListNode<int>(0);
    LinkedListNode<int>*nex;
    temp=result;
    while(it!=NULL)
    {
        nex=it->next->next;
        temp->next=it->next;
        temp=temp->next;
        it->next=nex;
        it=nex;

    }
    
    return result->next;
}
