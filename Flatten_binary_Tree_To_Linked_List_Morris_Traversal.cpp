#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure.

    template <typename T>
    class TreeNode {
        public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
   TreeNode<int> *curr=root;
   while(curr!=NULL){
       if(curr->left!=NULL){
           TreeNode<int> *prev = curr->left;
           while(prev->right){
               prev=prev->right;
           }
           prev->right=curr->right;
           curr->right=curr->left;
       }
       curr = curr->right;
   }
   return root;
}