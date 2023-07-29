#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

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
TreeNode<int> *solve(TreeNode<int> *root, int x, int y){
    if(root==NULL || root->data==x || root->data==y) return root;

    TreeNode<int> *left=solve(root->left,x,y);
    TreeNode<int> *right=solve(root->right, x,y);

    if(left!=NULL && right!=NULL) return root;
    else if(left!=NULL && right==NULL) return left;
    else if(left==NULL && right!=NULL) return right;
    else return NULL;
}
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	TreeNode<int> *ans= solve(root, x, y);
    return ans->data;
}