#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

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

*************************************************************/
pair<bool,int> fastbalanced(BinaryTreeNode<int>* root){
    if(root==NULL){
        pair<bool,int> p=make_pair(true,0);
        return p;
    }
    pair<int,int> left=fastbalanced(root->left);
    pair<int,int> right=fastbalanced(root->right);

    bool leftans=left.first;
    bool rightans=right.first;

    bool diff=abs(left.second-right.second)<=1;
    pair<bool,int> ans;
    ans.second=max(left.second,right.second)+1;
    if(leftans && rightans && diff){
        ans.first=true;
    }else{
        ans.first=false;
    }
    return ans;
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    return fastbalanced(root).first;
}