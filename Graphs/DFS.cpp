//Krishhhhh
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void dfs(int node, vector<ll> adj[], ll vis[], vector<ll> &ans){
    ans.push_back(node);
    for(auto it: adj[node]){
        if(!vis[it]){
            vis[it]=1;
            dfs(it, adj, vis, ans);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;

    // Creating a adj vector array
    vector<ll> adj[n+1];
    for(int i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        adj[v].push_back(u);
        adj[u].push_back(v); // undirected graph
    }

    // Setting up Pre-req
    ll vis[n+1]={0};
    ll node = 1;
    vis[1]=1;
    vector<ll> ans;
    dfs(node, adj, vis, ans);
    for(auto it : ans){ 
        cout<<it<<" ";
    }
}
