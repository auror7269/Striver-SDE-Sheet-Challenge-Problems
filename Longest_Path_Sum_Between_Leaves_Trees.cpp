#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
long long int solve(TreeNode<int> *root, long long int &ans){
    if(root==NULL) return -1;

    if(root->left==NULL && root->right==NULL) return root->val;

    long long int left=solve(root->left, ans);
    long long int right=solve(root->right, ans);
    

    if(root->left!=NULL && root->right!=NULL){
        ans = max(ans, left+right+root->val);
        return max(left,right)+root->val;
    }else if(root->left==NULL ){
        return right+root->val;
    }else {
        return left+root->val;
    }
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    long long int ans=-1;
    solve(root, ans);
    return ans;
}