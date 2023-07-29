#include <bits/stdc++.h> 
class Node{
	public:
		int h, li, ri;

		Node(int h, int li, int ri){
			this->h = h;
			this->li = li;
			this->ri = ri;
		}
};

int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int n){
	int ans = 0;
	queue<Node> q;

	Node root(0, 0, n-1);
	q.push(root);

	unordered_map<int, int> mp;
	for(int i = 0; i < n; i++) mp[inorder[i]] = i;
	
	for(int i = 0; i < n; i++){
		Node temp = q.front();
		q.pop();

		ans = max(ans, temp.h);

		int li = temp.li, ri = temp.ri;
		int rootIndexOfSubTree = mp[levelOrder[i]];

		if(rootIndexOfSubTree - 1 >= li){
			Node lst(temp.h+1, li, rootIndexOfSubTree-1);
			q.push(lst);
		}

		if(rootIndexOfSubTree + 1 <= ri){
			Node rst(temp.h+1, rootIndexOfSubTree+1, ri);
			q.push(rst);
		}

	}

	return ans;
}