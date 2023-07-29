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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{   
    vector<int> ans;
    if(root==NULL) return ans;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    bool leftToRight=true;
    while(!q.empty()){
        int size=q.size();
        vector<int> temp(size);
        for(int i=0;i<size;i++){
            BinaryTreeNode<int> *front=q.front();
            q.pop();
            int index=leftToRight? i: size-i-1;
            temp[index]=front->data;
            if(front->left!=NULL) q.push(front->left);
            if(front->right!=NULL) q.push(front->right);
        }
        leftToRight=!leftToRight;
        for(auto it: temp){
            ans.push_back(it);
        }
    }
    return ans;
}
