class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj (n+1);

        for(auto it : times){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt}); 
        }

        vector<int> dist(n + 1 , INT_MAX);

        priority_queue <pair<int,int> , vector<pair<int,int>>, greater<>> pq;

        pq.push({0, k});
        dist[k] = 0;

        while(!pq.empty()){
            int node = pq.top().second;
            int time = pq.top().first;
            pq.pop();

            for(auto it : adj[node]){
                int cur = it.first;
                int tt = it.second;

                int travel = time + tt;

                if(dist[cur] > travel){
                    dist[cur] = travel;
                    pq.push({travel, cur});
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){       
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;

    }

};
