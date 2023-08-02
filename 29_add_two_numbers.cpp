/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *p1, Node *p2)
{
    
    Node*dummy=new Node();
    Node*p=dummy;
    int carry=0;
    while(p1!=NULL || p2!=NULL || carry)
    {
        int s=0;
        if(p1!=NULL){s+=p1->data;p1=p1->next;}
        if(p2!=NULL){s+=p2->data;p2=p2->next;}
        s+=carry;

        Node*create=new Node(s%10);
       
        p->next=create;
        p=create;
        carry=s/10;
    }
   
    return dummy->next;
}
