#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int,vector<pair<int,int>>> adj;
    for(int i=0;i<g.size();i++){
        int u=g[i].first.first;
        int v=g[i].first.second;
        int w=g[i].second;

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    vector<int> key(n+1);
    vector<int> parent(n+1);
    vector<bool> mst(n+1);
    for(int i=0;i<=n;i++){
        parent[i]=-1;
        mst[i]=false;
        key[i]=INT_MAX;
    }
    key[1]=0;
    for(int j=1;j<n;j++){
        int mini=INT_MAX;
        int u;
        for(int i=1;i<=n;i++){
            if(mst[i]==false && key[i]<mini){
                u=i;
                mini=key[i];
            }
        }
        mst[u]=true;
        for(auto it:adj[u]){
            int v=it.first;
            int w=it.second;
            if(mst[v]==false && w<key[v]){
                key[v]=w;
                parent[v]=u;

            }
        }
    }
    vector<pair<pair<int, int>, int>> ans;
    for(int i=2;i<=n;i++){
      ans.push_back({{parent[i], i}, key[i]});
    }
    return ans;
}
