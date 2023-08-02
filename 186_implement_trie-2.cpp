#include <bits/stdc++.h> 

/*class TrieNode {                        //Definition of TrieNode class
public:
    TrieNode * children[26];
    bool isEnd;
    TrieNode()
    {
        isEnd=false;
        for(int i=0;i<26;i++)
            children[i]=NULL;
    }

};*/

TrieNode* solution::deleteWord(TrieNode* root, string word) {
  // base case
  if(word.length() == 0)
  {
    root->isEnd = false;
    return root;
  }


  int index = word[0] - 'a';
  if(root->children[index] != NULL)
    deleteWord(root->children[index],word.substr(1));
  return root;
}

