 #include <bits/stdc++.h> 

class LRUCache
{
public:
    class node{
        public:
        int val;
        int key;
        node* next;
        node* prev;
        node(int _key,int _val){
            key=_key;
            val=_val;
        }
        };
    unordered_map<int,node*> mp;
    node* head= new node(-1,-1);
    node* tail=new node(-1,-1);
    int cap;    
    
    LRUCache(int capacity)
    {
       cap=capacity;
       head->next=tail;
       tail->prev=head;
    }
    void addnode(node* root){
        node* temp=head->next;
        root->next=temp;
        root->prev=head;
        head->next=root;
        temp->prev=root;
    }
    void deletenode(node* root){
        node* nodeprev=root->prev;
        node* nodenext=root->next;
        nodeprev->next=nodenext;
        nodenext->prev=nodeprev;
    }
    int get(int key)
    {
       if(mp.find(key)!=mp.end()){
           node* temp=mp[key];
           int ans=temp->val;
           mp.erase(key);
           deletenode(temp);
           addnode(temp);
           mp[key]=head->next;
           return ans;
       }
       return -1;
    }

    void put(int key, int value)
    {
        if(mp.find(key)!=mp.end()){
            node* exist=mp[key];
            mp.erase(key);
            deletenode(exist);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        node* res= new node(key,value);
        addnode(res);
        mp[key]=head->next;

    }
};
