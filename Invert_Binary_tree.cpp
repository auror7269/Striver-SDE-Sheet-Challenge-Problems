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
bool storParents(TreeNode<int> *root, stack<TreeNode<int> *> &parents,
                 TreeNode<int> *leaf) {
  parents.push(root);

  if (!root->left and !root->right) {
    if (root->data == leaf->data)
      return true;
    else
      parents.pop();
    return false;
  }

  if (root->left) {
    if (storParents(root->left, parents, leaf))
      return true;
  }

  if (root->right) {
    if (storParents(root->right, parents, leaf))
      return true;
  }

  parents.pop();
  return false;
}
TreeNode<int> * invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf)
{
	if(root==NULL) return root;
    stack<TreeNode<int> *> s;
    storParents(root, s,leaf);
    TreeNode<int> *newroot=s.top();
    TreeNode<int> *parent=newroot;
    s.pop();
    while(!s.empty()){
        TreeNode<int> *temp=s.top();
        s.pop();
        if(temp->left==parent){
            parent->left=temp;
            temp->left=NULL;
        }else{
            temp->right=temp->left;
            temp->left=NULL;
            parent->left=temp;
        }
        parent=parent->left;
    }
    return newroot;
}
