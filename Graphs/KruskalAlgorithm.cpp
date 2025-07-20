// User function Template for C++
class DisjointSet {
    vector<int> parent, rank, size;
  public:
    DisjointSet (int n){
        parent.resize(n+1);
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        for(int i = 0 ; i <= n ; i ++){
            parent[i] = i;
        }
    }
    
    int findUpar(int u){
        if(parent[u] == u) return u;
        return parent[u] = findUpar(parent[u]);
    }
    
    void UnionbyRank(int u, int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        
        if(ulp_u == ulp_v) return;
        
        if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v; 
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    
    void UnionbySize(int u, int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        
        if(ulp_u == ulp_v) return;
        
        if(size[ulp_u] > size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] +=size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    
};


class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        vector<pair<int, pair<int,int>>> adj;
        
        DisjointSet ds(V);
        
        for(auto it : edges){
            adj.push_back({ it[2] , {it[0], it[1]}});
        }
        
        sort(adj.begin(), adj.end());
        int ans = 0;
        
        for(auto it : adj){
            if(ds.findUpar(it.second.first) != ds.findUpar(it.second.second)){
                ans += it.first;
                ds.UnionbyRank(it.second.first, it.second.second);
            }
        }
        return ans;
        
        
        
    }
};
