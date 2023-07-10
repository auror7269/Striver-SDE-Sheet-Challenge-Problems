#include <unordered_map>
bool solve(vector<int> adj[],vector<int> &color, int node ){
	for(auto i:adj[node]){
		if(color[i]==-1){
			color[i]= 1-color[node];
			if(!solve(adj, color, i)) return false;
		}else if(color[i]==color[node]) return false;
	}
	return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
	 
	int n = edges.size();
	 vector<int> adj[n];
 	 for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (edges[i][j]) {
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
    }
  }

	 vector<int> color(n, -1);
  for (int i = 0; i < n; i++) {
    if (color[i] == -1) {
      color[i] = 0;
      if (!solve(adj, color,i))
        return false;
    }
  }

  return true;
}