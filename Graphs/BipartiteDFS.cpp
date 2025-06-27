class Solution {
public:
    bool dfs(int node, int col, vector<int> &vis, vector<vector<int>> graph){
        for(auto it : graph[node]){
            if(vis[it]==-1){
                vis[it] = !col;
                if(dfs(it, !col, vis, graph)==false) return false;
            }
            else if(vis[it]==col) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        
        for(int i = 0 ; i < n ; i ++){
            if(vis[i]==-1){
                vis[i] = 0;
                if(dfs(i, 0, vis, graph)==false) return false;
            }
        }
        return true;
    }
};
