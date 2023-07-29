#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
     map<int, map<int, vector<int>>> mp;
     queue< pair<TreeNode<int>*, pair<int,int>>> q;
     vector<int> ans;
     if(root==NULL) return ans;
     q.push({root, {0,0}});
     
     while(!q.empty()){
         auto temp = q.front();
         q.pop();
         TreeNode<int> *node=temp.first;
         int hd = temp.second.first;
         int lvl = temp.second.second;
         mp[hd][lvl].push_back(node->data);
         if(node->left) q.push(make_pair(node->left, make_pair(hd-1, lvl+1)));

         if(node->right) q.push(make_pair(node->right, make_pair(hd+1, lvl+1)));
     }
     for(auto i:mp){
         for(auto j:i.second){
             for(auto k: j.second){
             ans.push_back(k);
         }
     }}
     return ans;
}