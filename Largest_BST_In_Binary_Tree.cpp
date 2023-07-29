#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
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
class info{
    public:
    int maxi;
    int mini;
    bool isbst;
    int size;
};
info solve(TreeNode<int>* root, int &ans){
    if(root==NULL){
        return {INT_MIN,INT_MAX, true, 0};
    }
    info left=solve(root->left, ans);
    info right=solve(root->right, ans);

    info curr;
    curr.size= left.size + right.size +1;
    curr.maxi = max(root->data,right.maxi);
    curr.mini = min(root->data, left.mini);

    if(left.isbst && right.isbst && (root->data>left.maxi && root->data <right.mini)){
        curr.isbst=true;
    }else{
        curr.isbst=false;
    }
    if(curr.isbst){
        ans = max(ans, curr.size);
    }
    return curr;
}
int largestBST(TreeNode<int>* root) 
{
    int ans=0;
    info temp=solve(root, ans);

    return ans;
}
