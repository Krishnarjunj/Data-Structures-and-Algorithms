#include <vector>
#include <unordered_set>  // ? Add this

using namespace std;

struct DSU {
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int findUpar(int u) {
        if (parent[u] == u)
            return u;
        return parent[u] = findUpar(parent[u]);
    }

    void UnionByRank(int u, int v) {
        int pu = findUpar(u);
        int pv = findUpar(v);
        if (pu == pv) return;

        if (rank[pu] < rank[pv])
            parent[pu] = pv;
        else if (rank[pu] > rank[pv])
            parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q) {
    vector<vector<int>> grid(n, vector<int>(m, 0));
    DSU dsu(n * m);
    vector<int> ans;

    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    int count = 0;

    for (auto &query : q) {
        int row = query[0];
        int col = query[1];
        int node = row * m + col;

        if (grid[row][col] == 1) {
            ans.push_back(count);
            continue;
        }

        grid[row][col] = 1;
        count++;

        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            int nnode = nrow * m + ncol;

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1) {
                int up1 = dsu.findUpar(node);
                int up2 = dsu.findUpar(nnode);
                if (up1 != up2) {
                    dsu.UnionByRank(up1, up2);
                    count--;
                }
            }
        }
        ans.push_back(count);
    }

    return ans;
}
