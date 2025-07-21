class Solution {
public:
    int MOD = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {
        using ll = long long;
        vector<vector<pair<int, int>>> adj(n);

        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

        vector<ll> dist(n, LLONG_MAX);  // ✅ fix here
        vector<int> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0}); // {distance, node}

        while (!pq.empty()) {
            ll dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (dis > dist[node]) continue;  // ✅ optimization

            for (auto& it : adj[node]) {
                int adjnode = it.first;
                int adjdis = it.second;

                if (dist[adjnode] > dis + adjdis) {
                    dist[adjnode] = dis + adjdis;
                    ways[adjnode] = ways[node];
                    pq.push({dist[adjnode], adjnode});
                } else if (dist[adjnode] == dis + adjdis) {
                    ways[adjnode] = (ways[adjnode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};
