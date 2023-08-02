/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
   if(head==NULL || head->next==NULL||k==0)return head;
   Node*p=head;
   int count=1;
   while(p->next!=NULL)
   {
      count++;
      p=p->next;
   }
   k=k%count;
   if(k==0)return head;
   k=count-k;
 
   p->next=head;
   while(k--)p=p->next;

   head=p->next;
   p->next=NULL;

   return head;
}
