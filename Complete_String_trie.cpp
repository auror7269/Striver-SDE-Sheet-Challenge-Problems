#include <bits/stdc++.h> 

class Node{
public:
    bool flag = false;
    Node* links[26]; 
    bool contains(char c){
        return links[c - 'a'] != nullptr;
    }
    void put(char c){
        links[c - 'a'] = new Node();
    }
    Node* next(char c){
        return links[c - 'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie{
public:
    Node* root;
    Trie(){
        root = new Node();
    }
    void insert(string s){
        Node* tmp = root;
        for(int i = 0; i < s.size(); ++i){
            if(!tmp->contains(s[i])){
                tmp->put(s[i]);
            }
            tmp = tmp->next(s[i]);
        }
        tmp->setEnd();
    }
    bool search(string s){
        Node* tmp = root;
        for(auto c : s){
            tmp = tmp->next(c);
            if(!tmp->isEnd()) return false;
        }
        return true;
    }
};

string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie* trie = new Trie();
    for(auto s : a){
        trie->insert(s);
    }
    string ans;
    for(auto s : a){
        if(trie->search(s)){
            if(s.size() > ans.size()) ans = s;
            else if(s.size() == ans.size()){
                if(s < ans) ans = s;
            }
        }
    }
    if(ans.size() == 0) return "None";
    return ans;
}