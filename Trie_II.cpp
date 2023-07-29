#include <bits/stdc++.h> 
using namespace std;


class Node {
public:
    char data;
    unordered_map<char, Node*> children;
    bool isTerminal;
    int terminalCount;
    int prefix;


    Node(char d){
        data = d;
        isTerminal = false;
        terminalCount = 0;
        prefix=0;
    }
};


class Trie{
    Node *root;
    public:
    Trie(){
        root = new Node('\0');
    }


    void insert(string &word){
        Node *curr = root;
        for(int i=0;i<word.length();i++){
            char ch = word[i];
            if(curr->children[ch]!=NULL)
                curr = curr->children[ch];
            else{
                Node *n = new Node(ch);
                curr->children[ch] = n;
                curr = n;
            }
            curr->prefix++;
        }
        curr->isTerminal = true;
        curr->terminalCount++;
    }


    int countWordsEqualTo(string &word){
        Node *curr = root;


        for(int i=0;i<word.length();i++){
            char ch = word[i];
            if(curr->children[ch]!=NULL){
                curr = curr->children[ch];
            }else{
                return 0;
            }
        }
        return curr->terminalCount;
    }


    int countWordsStartingWith(string &word){
        Node *curr = root;
        for(int i=0;i<word.length();i++){
            char ch = word[i];
            if(curr->children[ch]!=NULL)
                curr = curr->children[ch];
            else
                return 0;
        }


        // int wordCount = 0;
        // // Traverse children and sum up their children count
        // queue<Node*> q;
        // q.push(curr);


        // while(!q.empty()){
        //     Node *f = q.front();
        //     q.pop();
        //     wordCount += f->terminalCount;


        //     for(auto child: f->children){
        //         q.push(child.second);
        //     }
        // }


        // return wordCount;
        return curr->prefix;
    }


    void erase(string &word){
        Node *curr = root;
        for(int i=0;i<word.length();i++){
            char ch = word[i];
            if(curr->children[ch]!=NULL){
                curr = curr->children[ch];
                curr->prefix--;
            }else{
                return;
            }
        }


        if (curr->isTerminal){
          if (curr->terminalCount == 1) {
            curr->isTerminal = false;
            curr->terminalCount = 0;
          } else
            curr->terminalCount--;
        }
    }
};