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
void solve(TreeNode<int> *root, int &i,int k, int &ans){
    if(root==NULL){
        return ;
    }
    solve(root->left, i, k, ans);
   
    i++;
    if(i==k)  ans=root->data;

    solve(root->right, i, k, ans);
}
int kthSmallest(TreeNode<int> *root, int k)
{
    int i=0;
    int ans=1;
	solve(root, i, k,ans);
    return ans;
}