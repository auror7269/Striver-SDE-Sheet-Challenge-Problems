#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
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
void traverseleft(TreeNode<int>* root, vector<int> &ans){
    if(root==NULL || (root->left==NULL && root->right==NULL)) return;

    ans.push_back(root->data);
    if(root->left!=NULL)
          traverseleft(root->left, ans);
    else 
        traverseleft(root->right, ans);

    return;          
}
void traverseleaf(TreeNode<int>* root,vector<int> &ans){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
    }
    traverseleaf(root->left, ans);
    traverseleaf(root->right,ans);

    return;
}
void traverseright(TreeNode<int>* root, vector<int> &ans){
    if(root==NULL || (root->left==NULL && root->right==NULL)) return;

    
    if(root->right!=NULL)
          traverseright(root->right, ans);
    else 
        traverseright(root->left, ans);
    ans.push_back(root->data);
    return;          
}
vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    ans.push_back(root->data);

    traverseleft(root->left,ans);

    traverseleaf(root->left, ans);
    traverseleaf(root->right, ans);

    traverseright(root->right, ans);
    return ans;
}