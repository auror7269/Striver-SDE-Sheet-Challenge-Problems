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
TreeNode<int>* solve(vector<int> &inorder, vector<int> &preorder,
int &index, int inorderstart, int inorderend,int n, map<int,int> &mp){
    if(index>=n || inorderstart>inorderend) return NULL;
    
    int element = preorder[index++];
    TreeNode<int> *root = new TreeNode<int>(element);

    int pos = mp[element];
    root->left= solve(inorder, preorder, index, inorderstart, pos-1, n, mp);
    root->right= solve(inorder, preorder, index,pos+1,inorderend, n, mp);

    return root;

}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	map<int,int> mp;
    for(int i=0;i<inorder.size();i++){
        mp[inorder[i]]=i;
    }
    int n=inorder.size();
    int index=0;
    return solve(inorder, preorder,index , 0, n-1, n, mp);

   
}