// tire implementation // 
//ques link->   https://leetcode.com/problems/implement-trie-prefix-tree/
#include <bits/stdc++.h>
using namespace std;
struct Trienode{
       bool isend=false;
      int count=0;
      char d;
      Trienode *child[26];
};
Trienode *root;
Trienode* getnode(int index){
    Trienode *temp=new Trienode;
    temp->d=index+'a';
    for(int i=0;i<26;i++){
        temp->child[i]=NULL;
    }
    return temp;
}
class Trie {
public:
    Trie(){
        root=getnode('/'-'a');
    }
    void insert(string word){
        Trienode *curr=root;
        int index;
        for(int i=0;i<word.length();i++){
            index=word[i]-'a';
            if(curr->child[index]==NULL){
                curr->child[index]=getnode(index);
                }
            curr->child[index]->count+=1;
            curr=curr->child[index];
            }
            curr->isend=true;
        }
    bool search(string word) {
        Trienode *curr=root;
        for(int i=0;i<word.length();i++){
            int index=word[i]-'a';
            curr=curr->child[index];
            if(curr==NULL){
                return false;
            }
        }
        if(curr!=NULL and curr->isend)
        {
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        Trienode *curr =root;
        int index;
        for(int i=0;i<prefix.size();i++){
            index=prefix[i]-'a';
            curr=curr->child[index];
            if(curr==NULL){
                return false;
            }
        }
        if(curr->count>0){
            return true;
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */


// time complexity --->
// O(length(longest string)* Query)
//Space-> O(217*NO of nodes)