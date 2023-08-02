#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
pair<Node*,Node*> reverse(Node*head){
	pair<Node*,Node*>ans;
	Node*tail=NULL;
	Node*prev=NULL;
	Node*curr=head;
	while(curr!=NULL)
	{
		Node*temp=curr->next;
		curr->next=prev;
		if(tail==NULL)tail=curr;
		prev=curr;
		curr=temp;
	}
     ans.first=prev;
	 ans.second=tail;
	 return ans;
}
Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	Node*p=head;
	Node*q=head;
	Node*ans=head;
	Node*tail=NULL;
	for(int i=0;i<n;i++)
  {
		if(b[i]==0)continue;
    if(p==NULL)break;
    
		while(q->next!=NULL && b[i]-->1)q=q->next;
   
         Node*temp = q->next;
         q->next = NULL;
		     pair<Node*,Node*>rev=reverse(p);
            
         if (tail != NULL) {
            tail->next = rev.first;
            tail = rev.second;
         }
			  else{
				    ans=rev.first;
				    tail=rev.second;
			   }

            p=temp;
		      	q=p;	
    }
   	if(tail!=NULL)tail->next=p;
	return ans;
}
