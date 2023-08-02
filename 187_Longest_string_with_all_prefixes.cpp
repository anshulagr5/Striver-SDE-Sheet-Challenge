#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node* links[26];
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }

    Node* get(char ch){
        return links[ch-'a'];
    }
};

class Trie {
private:
Node* root;

public:

    /** Initialize your data structure here. */
    Trie() {
        root=new Node();
    }

    void insert(string word) {
        int n=word.size();
        Node* node=root;
        for(int i=0;i<n;i++){
            char ch=word[i];
            if(!node->containsKey(ch)){
                node->links[ch-'a']=new Node();
            }
            node=node->get(ch);
        }
        return;
    }

    string solve(vector<string> &arr, int n){
        string s="";
        int commonprefixIndex=-1;
        insert(arr[0]);
            for(int i=1;i<n;i++){
                Node* node=root;
                int p=arr[i].size();
                string temp="";
                for(int j=0;j<p;j++){
                    char ch=arr[i][j];
                    if(!node->containsKey(ch)){
                        if(temp=="") return temp;
                        if(s==""){
                            s=temp;
                        }
                        else{
                                if(temp.length()<s.length()){
                            s=temp;
                           }
                        }
                        break;
                    } 
                    else{
                        temp+=ch;
                        node = node->get(ch);
                    }
                }
            }
      return s;
   }
   
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    string s="";
    Trie trie;
    s=trie.solve(arr,n);
    return s;
}
