// Krishhhhh
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Disjointset {
    vector<int> parent;
    vector<int> rank;

public:
    Disjointset(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findUPar(parent[node]); // Path compression
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        } else if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Disjointset ds(7);

    ds.unionByRank(1, 2);
    ds.unionByRank(1, 3);
    ds.unionByRank(3, 4);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);

    if (ds.findUPar(5) == ds.findUPar(7)) {
        cout << "ah hy" << endl;
    } else {
        cout << "ah hn" << endl;
    }

    cout << ds.findUPar(5) << " " << ds.findUPar(7) << endl;
}
