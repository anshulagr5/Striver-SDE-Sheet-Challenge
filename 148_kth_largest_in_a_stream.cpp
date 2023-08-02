#include <bits/stdc++.h> 
class Kthlargest {
    private:
    priority_queue<int,vector<int>,greater<int>>minh;
    
public:
    Kthlargest(int k, vector<int> &arr) {
       for(int i=0;i<k;i++)
              minh.push(arr[i]);
    }

    void add(int num) {
       minh.push(num);
       minh.pop();

    }

    int getKthLargest() {
       return minh.top();
    }

};
