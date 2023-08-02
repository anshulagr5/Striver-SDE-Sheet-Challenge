#include <bits/stdc++.h> 
struct Node{
      int key;
      int value;
      int count;
      Node*prev;
      Node*next;
      Node(int k,int v){
          key=k;
          value=v;
          count=1;
      }
};
struct List{
     int size;
     Node*head;
     Node*tail;
     List(){
         head=new Node(-1,-1);
         tail=new Node(-1,-1);
         head->next=tail;
         tail->prev=head;
         size=0;
     }

     void addFront(Node*given){
         Node*temp=head->next;
         head->next=given;
         given->next=temp;
         given->prev=head;
         temp->prev=given;
         size++;
     }

     void deleteNode(Node*given){
         Node*delprev=given->prev;
         Node*delnext=given->next;
         delprev->next=delnext;
         delnext->prev=delprev;
         size--;
     }
};


class LFUCache
{
    map<int,Node*>keynode;
    map<int,List*>freqListMap;
    int maxSizeCache;
    int minFreq;
    int currsize;

public:
    LFUCache(int capacity)
    {
        maxSizeCache=capacity;
        minFreq=0;
        currsize=0;
    }
    void updateFreqList(Node*node){
        keynode.erase(node->key);
        freqListMap[node->count]->deleteNode(node);
        if(node->count ==minFreq && freqListMap[node->count]->size==0)minFreq++;

        List * Nexthigherlist=new List();
        if(freqListMap.find(node->count+1)!=freqListMap.end())
          Nexthigherlist=freqListMap[node->count+1];
        node->count+=1;
        Nexthigherlist->addFront(node);
        freqListMap[node->count]=Nexthigherlist;
        keynode[node->key]=node;

    }
    int get(int key)
    {
       if(keynode.find(key)!=keynode.end()){
           Node*find=keynode[key];
           int val=find->value;
           updateFreqList(find);
           return val;
       }
       return -1;
    }

    void put(int key, int value)
    {
        if(maxSizeCache==0)return;
        if(keynode.find(key)!=keynode.end()){
           Node*find=keynode[key];
           find->value=value;
           updateFreqList(find);
       }
       else{
           if(currsize==maxSizeCache){
               List* list=freqListMap[minFreq];
              keynode.erase(list->tail->prev->key);
              list->deleteNode(list->tail->prev);
              currsize--;
           }
           currsize++;

           minFreq=1;
           List* listfreq=new List();
           if(freqListMap.find(minFreq)!=freqListMap.end())
             listfreq=freqListMap[minFreq];

           Node *node=new Node(key,value);
           listfreq->addFront(node);
           keynode[key]=node;
           freqListMap[minFreq]=listfreq;

       }
    }
};
