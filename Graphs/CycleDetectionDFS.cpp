class Solution {
  public:
    bool dfs(int node, int parent, vector<int>& vis, vector<vector<int>>& adj){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            if(vis[it]==-1){
                if(dfs(it, node, vis, adj)) return true;
            }
            else if(it != parent) return true;
        }
        
        return false;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> vis(V, -1);
        
        vector<vector<int>> adj(V);
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i = 0 ; i < V ; i ++){
            if(vis[i]==-1){
                if(dfs(i , -1 , vis, adj)) return true;
            }
        }
        return false;
        
    }
};
