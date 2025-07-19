class Solution {
  public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> vis(V, 0);
        
        pq.push({0, 0}); // {weight, node}
        int sum = 0;
        
        while (!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if (vis[node]) continue;
            
            vis[node] = 1;
            sum += wt;
            
            for (auto it : adj[node]) {
                int adjNode = it[0];
                int edgeWeight = it[1];
                
                if (!vis[adjNode]) {
                    pq.push({edgeWeight, adjNode});
                }
            }
        }
        
        return sum;
    }
};
