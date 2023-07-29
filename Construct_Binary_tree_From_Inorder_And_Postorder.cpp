/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
 #include <map>
TreeNode<int>* solve(vector<int>& postOrder, vector<int>& inOrder,
int &index, int inorderstart, int inorderend, int n, map<int,int> &mp){
     if(index<0 || inorderstart>inorderend){
          return NULL;
     }
     int element = postOrder[index--];
     int pos = mp[element];
     TreeNode<int>* root = new TreeNode<int>(element); 
     root->right = solve(postOrder, inOrder, index, pos+1,inorderend, n, mp);
     root->left = solve(postOrder, inOrder, index, inorderstart, pos-1, n, mp);
     
     return root;
}
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	int index=postOrder.size()-1;
     int n=inOrder.size();
     map<int,int> mp;
     for(int i=0;i<inOrder.size();i++){
          mp[inOrder[i]]=i;
     }

     return solve(postOrder, inOrder, index, 0, n-1, n, mp);
}
