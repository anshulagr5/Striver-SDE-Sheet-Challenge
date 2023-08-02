/****************************************************************

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


*****************************************************************/
Node* detectcycle(Node*head)
{
    if(head==NULL || head->next==NULL)return NULL;
    Node*slow=head;
    Node*fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)return fast; 
    }
    return NULL;
}
Node *firstNode(Node *head)
{
    if(head==NULL || head->next==NULL)return NULL;
     Node*p=head;
     Node*common=detectcycle(head);
     if(common==NULL)return NULL;
     
         while(p!=common)
         {
             p=p->next;
             common=common->next;
         }

     return common;
}
