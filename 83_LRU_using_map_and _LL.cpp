#include<bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
    class Node{
        public:
        Node* next;
        Node*prev;
        int k;
        int v;
        Node(int key,int value)
        {
            k=key;
            v=value;
        }
    };
    Node*head=new Node(-1,-1);
    Node*tail=new Node(-1,-1);

    unordered_map<int,Node*>umap;
    int cap;

    LRUCache(int capacity)
    {
       cap=capacity;
       head->next=tail;
       tail->prev=head;
    }
    void addNode(Node*given){
        Node*temp=head->next;
        head->next=given;
        given->next=temp;
        given->prev=head;
        temp->prev=given;
    }

    void deleteNode(Node*given){
        Node*temp=given->next;
        given->prev->next=temp;
        temp->prev=given->prev;
        given->prev=NULL;
        given->next=NULL;
    }

    int get(int key)
    {
        if(umap.find(key)==umap.end())
            return -1;
        Node*find=umap[key];
        int value=find->v;
        umap.erase(key);
        deleteNode(find);
        addNode(new Node(key,value));
        umap[key]=head->next;
        return value;
    }

    void put(int key, int value)
    {
       if(umap.find(key)!=umap.end()){
           Node*find=umap[key];
           umap.erase(key);
           deleteNode(find);
       }
       if(umap.size()==cap){
           int tkey=tail->prev->k;
           umap.erase(tkey);
           deleteNode(tail->prev);
       }
       Node*New=new Node(key,value);
       addNode(New);
       umap[key]=head->next;
    }
};
