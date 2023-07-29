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
pair<int,int> fastdiamter(TreeNode<int> *root){
    if(root==NULL){
        pair<int,int> p=make_pair(0,0);
        return p;
    }
    pair<int,int> left=fastdiamter(root->left);
    pair<int,int> right=fastdiamter(root->right);

    int op1=left.first;
    int op2=right.first;
    int op3=left.second+right.second;

    pair<int,int> ans;
    ans.first=max(op1, max(op2,op3));
    ans.second=max(left.second,right.second)+1;
    return ans;

}
int diameterOfBinaryTree(TreeNode<int> *root)
{
	return fastdiamter(root).first;
}
