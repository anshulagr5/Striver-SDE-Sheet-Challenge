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

Node* removeKthNode(Node* head, int K)
{
    int count=0;
    Node*p=head;
    while (p != NULL) {
      count++;
      p = p->next;
    }
    K=count-K+1;
    if(K==1)return head->next;
    p=head;
    
    while(K!=2)
    {
        K--;
        p=p->next;
    }
      Node*q=NULL;
      q = p->next;
      p->next = q->next;

    return head;
}
