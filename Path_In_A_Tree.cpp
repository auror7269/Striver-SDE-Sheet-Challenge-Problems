#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/


void rec(TreeNode<int> *root, int x,vector<int>&ans)

{
    if(!root)
    return;
    ans.push_back(root->data);
    if(root->data==x)
    return;
    rec(root->left,x,ans);
    rec(root->right,x,ans);
	
    if(ans[ans.size()-1]!=x)
    ans.pop_back();
}

vector<int> pathInATree(TreeNode<int> *root, int x)

{   if(!root)
    return {};
    vector<int>ans;
    rec(root,x,ans);
    return ans;
}
