#include <bits/stdc++.h> 
class Node{
    public:
    Node* links [26];
    bool flag=false;
    bool isContains(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node* node)
    {
        links[ch-'a']=node;
    }
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    bool isEnd()
    {
        return flag;
    }
    void setEnd()
    {
        flag=true;
    }
};
class Trie{
    public:
     Node* root;
    Trie()
    {
        root=new Node();
    }
    void insert(string & word)
    {
        Node* node=root;
        for (int i=0;i<word.size();i++)
        {
            if (!node->isContains(word[i]))
            {
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    bool search(string &target,int low,int high)
    {
        Node* node=root;
        for (int i=low;i<=high;i++)
        {
            if (!node->isContains(target[i])) return false;
            node=node->get(target[i]);
        }
        return node->isEnd();
    }
   bool helper(int ind,vector<int>&dp,string & target)
   {
       if (ind==target.size()) return true;
       if (dp[ind]!=-1) return dp[ind];
       for (int i=ind;i<target.size();i++)
       {
           if (search(target,ind,i) && helper(i+1,dp,target))
           return dp[ind]=1;
       }
       return dp[ind]=0;
   }
};
bool wordBreak(vector < string > & arr, int n, string & target) 
{
     Trie* trie=new Trie();
     for (int i=0;i<n;i++)
     {
         trie->insert(arr[i]);
     }
     int sz=target.size();
     vector<int>dp(sz,-1);
     return trie->helper(0,dp,target);
}