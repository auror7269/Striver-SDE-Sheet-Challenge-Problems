#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int,vector<pair<int,int>>> adj;
    for(int i=0;i<edges;i++){
        int u=vec[i][0];
        int v=vec[i][1];
        int w=vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    set<pair<int,int>> s;
    unordered_map<int,int> visited;
    vector<int> dist(vertices);
    for(int i=0;i<vertices;i++){
        dist[i]=INT_MAX;
    }
    s.insert(make_pair(0,source));
    dist[source]=0;
    while(!s.empty()){
        auto t= *(s.begin());
        int node= t.second;
        int dis=t.first;
        
        s.erase(s.begin());
        for(auto i : adj[node]){
            if(dis+i.second <dist[i.first]){
                auto rec = s.find(make_pair(dist[i.first], i.first));

                if(rec!=s.end()){
                    s.erase(rec);
                }
                dist[i.first]=dis+i.second;

                s.insert(make_pair(dist[i.first],i.first));
            }
        }
    }
    return dist;
}
