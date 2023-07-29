#include <bits/stdc++.h> 

class Node{
    public:
    Node* links[26];
};
void insert(Node* root,string &s,int &cnt)
{
    int n=s.length();
    Node* cur=root;
    for(int i=0;i<n;i++)
    {   if(cur->links[s[i]-'a']==NULL)
        {
            cnt++;
            cur->links[s[i]-'a']=new Node();
        }
        cur=cur->links[s[i]-'a'];
    }
}
int distinctSubstring(string &word) {
    int n=word.length();
    Node* root=new Node();
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        string s;
        for(int j=i;j<n;j++)
        {
            s+=word[j];
            insert(root,s,cnt);
        }
    }
    return cnt;
}

 