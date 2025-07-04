class Solution {
  public:
    void topo(int node, vector<vector<pair<int,int>>> &adj, vector<int> &vis, stack<int>& st){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it.first]) topo(it.first, adj, vis, st);
        }
        st.push(node);
    }

    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        for(auto it : edges){
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> vis(V, 0);  
        stack<int> st;
        for(int i = 0; i < V; i++){
            if(vis[i] == 0) topo(i, adj, vis, st);
        }

        vector<int> dist(V, INT_MAX);
        dist[0] = 0;

        while(!st.empty()){
            int node = st.top();
            st.pop();

            if(dist[node] != INT_MAX){
                for(auto it : adj[node]){
                    int v = it.first;
                    int wt = it.second;

                    if(dist[node] + wt < dist[v]){
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }

        for(int i = 0 ; i < V ; i ++){
            if(dist[i] == INT_MAX) dist[i] = -1;
        }

        return dist;
    }
};
