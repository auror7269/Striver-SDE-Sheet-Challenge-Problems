#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>

    class BinaryTreeNode {
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

***********************************************************/

bool identicalTrees(BinaryTreeNode<int>* r1, BinaryTreeNode<int>* r2) {
    if(r1==NULL && r2==NULL) return true;

    if(r1==NULL && r2!=NULL) return false;

    if(r1!=NULL && r2==NULL) return false;
    bool left=identicalTrees(r1->left, r2->left);
    bool right=identicalTrees(r1->right, r2->right);

    bool val = r1->data==r2->data;
    if(left && right && val){
        return true;
    }	else{
        return false;
    } 
    
}