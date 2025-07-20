//Krishhhhh
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class DisjointSet{
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

public:
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1, 0);
        size.resize(n+1, 1);

        for(int i = 0 ; i <= n ; i ++){
            parent[i] = i;
        }
    }

    int findUparent(int u){
        if(parent[u] == u) return u;
        return parent[u] = findUparent(parent[u]);
    }

    void UnionbyRank(int u , int v){
        int ulp_u = findUparent(u);
        int ulp_v = findUparent(v);

        if(ulp_u == ulp_v) return;

        if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }

        else if(rank[ulp_v] > rank[ulp_u]){
            parent[ulp_u] = ulp_v; 
        }

        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u] ++;
        }
    }

    void UnionbySize(int u, int v){
        int ulp_u = findUparent(u);
        int ulp_v = findUparent(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];   
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    DisjointSet ds(8);

    ds.UnionbySize(1,2);
    ds.UnionbySize(2,3);
    ds.UnionbySize(1,4);
    ds.UnionbySize(4,5);
    ds.UnionbySize(6,7);
    ds.UnionbySize(7,8);

    if(ds.findUparent(8) == ds.findUparent(4)) cout<<"ah hy";
    else cout<<"ah hn";
}
