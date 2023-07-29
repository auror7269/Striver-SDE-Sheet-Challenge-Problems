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
BinaryTreeNode<int>* solve(BinaryTreeNode<int>* root,
BinaryTreeNode<int>* &prev, BinaryTreeNode<int>* &head){
    if(root==NULL) return NULL;

    solve(root->left, prev, head);

    if(prev==NULL) head=root;
    else {
        root->left=prev;
        prev->right=root;
    }
    prev=root;
    solve(root->right, prev , head);
}
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    BinaryTreeNode<int>* prev=NULL;
    BinaryTreeNode<int>* head=NULL;
    solve(root, prev, head);
    return head;
}