class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        vector<int> dist(adj.size(), INT_MAX);
        dist[src] = 0;
        queue<pair<int,int>> q;
        vector<int> ans;
        q.push({src,0});
        
        while(!q.empty()){
            int node = q.front().first;
            int dis = q.front().second;
            q.pop();
            
            for(auto it : adj[node]){
                if(dis + 1 < dist[it]){
                    dist[it] = dis + 1;
                    q.push({it, dist[it]});
                }
            }
            
        }
        for(int i = 0 ; i < adj.size() ; i ++){
            if(dist[i] == INT_MAX){
                dist[i] = -1;
            }
        }
        return dist;
        
    }
};
