/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node *findMiddle(Node *head) {
    int count=0;
    Node *p=head;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    p=head;
    count/=2;
    while(count--)p=p->next;
    
    return p;
}

