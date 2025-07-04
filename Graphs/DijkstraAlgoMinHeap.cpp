// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
        vector<vector<pair<int,int>>> adj(V);
        for(auto it : edges){
            adj[it[0]].push_back({it[2],it[1]});
        }
        
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        pq.push({0,src});
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){
                int wt = it.first;
                int u = it.second;
                
                if(dist[u] > dis + wt){
                    dist[u] = dis + wt;
                    pq.push({dist[u], u});
                }
            }
        }
        
        return dist;
    }
};
