#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
void inorder(BinaryTreeNode<int> *root, vector<int> &ans){
    if(root==NULL) return;

    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
  vector<int> temp;
  inorder(root, temp);
  int i=0,j=temp.size()-1;
  while(i<j){
      if(temp[i]+temp[j]==k) return true;
      else if(temp[i]+temp[j]>k) j--;
      else i++;
  }
  return false;
}