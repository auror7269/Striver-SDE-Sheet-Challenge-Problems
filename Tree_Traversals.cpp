#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/
void ino(BinaryTreeNode<int> *root,vector<int>&ans)

{
    if(root==NULL) return;
    ino(root->left,ans);
    ans.push_back(root->data);
    ino(root->right,ans);
}
void pre(BinaryTreeNode<int> *root,vector<int>&ans)
{
    if(root==NULL) return;
    ans.push_back(root->data);
    pre(root->left,ans);
    pre(root->right,ans);
}
void pos(BinaryTreeNode<int> *root,vector<int>&ans)
{
    if(root==NULL) return;
    pos(root->left,ans);
    pos(root->right,ans);
    ans.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>> ans;
    vector<int>temp;
    ino(root,temp);
    ans.push_back(temp);
    temp.clear();
    pre(root,temp);
    ans.push_back(temp);
    temp.clear();
    pos(root,temp);
    ans.push_back(temp);
    return ans;
}