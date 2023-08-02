#include<bits/stdc++.h>
using namespace std;
class Queue {
     stack<int>s1;
     stack<int>s2;
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
       s1.push(val);
    }

//PUSH-EFFICIENT SOLUTION
    int deQueue() {
        if(s1.size()==0)return -1;
        while(s1.size()!=0)
        {
            s2.push(s1.top());
            s1.pop();
        }
    
        int temp=s2.top();
        s2.pop();
        while(s2.size()!=0)
        {
            s1.push(s2.top());
            s2.pop();
        }
        return temp;
    }

    int peek() {
       if(s1.size()==0)return -1;
        while(s1.size()!=0)
        {
            s2.push(s1.top());
            s1.pop();
        }
    
        int temp=s2.top();
        while(s2.size()!=0)
        {
            s1.push(s2.top());
            s2.pop();
        }
        return temp;
    }

    bool isEmpty() {
        return (s1.size()==0)?true:false;
    }
};
