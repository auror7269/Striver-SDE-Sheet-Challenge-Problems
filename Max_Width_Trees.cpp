#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int getMaxWidth(TreeNode<int> *root)
{
    if(root==NULL) return 0;

    queue<pair<TreeNode<int> *, int>> q;
    q.push({root,0});
    int ans=0;
    while(!q.empty()){
        int size=q.size();
        int mini=q.front().second;
        int first,last;
        for(int i=0;i<size;i++){
            int curr=q.front().second-mini;
            TreeNode<int> * temp=q.front().first;
            q.pop();
            if(i==0) first=i;
            if(i==size-1) last=i;
            if(temp->left) q.push({temp->left, 2*curr+1});
            if(temp->right)
              q.push({temp->right, 2 * curr + 2});
        }
        ans = max(ans, last-first+1);
    }
    return ans;
}