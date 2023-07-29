#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void solve(TreeNode<int>* root, int &i, int k, int &ans){
    if(root==NULL) return;
    solve(root->right, i, k, ans);
    i++;
    if(i==k) ans=root->data;

    solve(root->left, i,k, ans);
}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
   int i=0;
   int ans=-1;
   solve(root, i, k, ans);
   return ans;
}
