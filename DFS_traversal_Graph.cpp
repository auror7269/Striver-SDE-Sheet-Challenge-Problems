void dfs(unordered_map<int, vector<int>> &adj, unordered_map<int,bool> &visited
, vector<int> &component, int node){
    component.push_back(node);
    visited[node]=true;
    for(auto i: adj[node]){
        if(!visited[i]){
            dfs(adj,visited,component, i);
        }
    }
}


vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int, vector<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int,bool> visited;
    vector<vector<int>> ans;
    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector<int> component;
            dfs(adj, visited, component, i);
            ans.push_back(component);
        }
    }
    return ans;
}