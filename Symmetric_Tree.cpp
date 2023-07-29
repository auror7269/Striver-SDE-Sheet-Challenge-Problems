/*****************************************************

    Following is the Binary Tree node structure:
    
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
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/
bool solve(BinaryTreeNode<int>* r1, BinaryTreeNode<int>* r2){
    if(r1==NULL|| r2==NULL) return true;

    if(r1->data!=r2->data) return false;

    return solve(r1->left, r2->right)&&solve(r1->right,r2->left);


}

bool isSymmetric(BinaryTreeNode<int>* root)
{
       if(root==NULL) return true;

       return solve(root->left, root->right);
}