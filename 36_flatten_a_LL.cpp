/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
Node* mergetwoLL(Node*p,Node*q)
{
	Node*dummy=new Node(0);
	Node*res=dummy;
	while(p!=NULL && q!=NULL)
	{
		if(p->data<q->data){
		   dummy->child=p;
		   dummy=dummy->child;
		   p=p->child;
		}
		else{
			dummy->child=q;
			dummy=dummy->child;
			q=q->child;
		}

	}
	if(q)dummy->child=q;
	else dummy->child=p;

	return res->child;
}
Node* flattenLinkedList(Node* head) 
{
	if(head==NULL || head->next==NULL)return head;
  
	Node*temp=flattenLinkedList(head->next);
  
	head->next=NULL;// make next pointer of head-> NULL because when we will return sorted List at that time we need only one reference pointer(child) otherwise it will create confusion.
  
  head=mergetwoLL(head,temp);
  
	return head;
}
