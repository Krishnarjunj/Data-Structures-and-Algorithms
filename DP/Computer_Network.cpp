class Solution {

    struct DSU {
        vector<int> parent;
        vector<int> rank;  // rank = approx height

        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);  // initially height = 0
            for (int i = 0; i < n; i++) parent[i] = i;
        }

        int findUpar(int u) {
            if (parent[u] == u) return u;
            return parent[u] = findUpar(parent[u]);  // path compression
        }

        void UnionByRank(int u, int v) {
            int up = findUpar(u);
            int vp = findUpar(v);
            if (up == vp) return;  // already in same component

            // attach smaller rank under larger rank
            if (rank[up] < rank[vp]) {
                parent[up] = vp;
            } else if (rank[vp] < rank[up]) {
                parent[vp] = up;
            } else {
                parent[vp] = up;
                rank[up]++;  // height increases only if ranks are same
            }
        }
    };

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;

        DSU dsu(n);

        for (auto& it : connections) {
            int u = it[0];
            int v = it[1];
            dsu.UnionByRank(u, v);
        }

        int components = 0;
        for (int i = 0; i < n; i++) {
            if (dsu.findUpar(i) == i) components++;
        }

        return components - 1;
    }
};
