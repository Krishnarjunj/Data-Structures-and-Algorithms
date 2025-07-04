// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adj(V);
        for(auto it : edges){
            adj[it[0]].push_back({it[2], it[1]});
        }
        set<pair<int,int>> st;
        vector<int> dist(V, INT_MAX);
        
        dist[src] = 0;
        st.insert({0, src});
        
        while(!st.empty()){
            auto it = *(st.begin());
            int wt = it.first;
            int u = it.second;
            st.erase({wt,u});
            
            for(auto itt : adj[u]){
                if(dist[itt.second] > wt + itt.first){
                    
                    if(dist[itt.second]!=INT_MAX) st.erase({itt.first, itt.second});
                    dist[itt.second] = wt + itt.first;
                    st.insert({dist[itt.second], itt.second});
                }
            }
        }
        return dist;
    }
};
