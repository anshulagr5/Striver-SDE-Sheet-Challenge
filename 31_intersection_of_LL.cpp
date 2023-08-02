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
int difference(Node*node1, Node * node2)
{
    int diff=0;
    while (node1 != NULL || node2!=NULL) {
      if (node1 != NULL) {
        diff++;
        node1 = node1->next;
      }
      if(node2!=NULL){
          diff--;
          node2=node2->next;
      }
    }
    return diff;
}
Node* findIntersection(Node *firstHead, Node *secondHead)
{
    int diff=difference(firstHead,secondHead);
    if(diff>=0){
        while(diff>0){
            firstHead=firstHead->next;
            diff--;
        }
    }
    else{
        while(diff<0){
            secondHead=secondHead->next;
            diff++;
        }
    }
    while(firstHead!=NULL && secondHead!=NULL){
        if(firstHead==secondHead)return firstHead;
        firstHead=firstHead->next;
        secondHead=secondHead->next;
    }
    return NULL;
}
