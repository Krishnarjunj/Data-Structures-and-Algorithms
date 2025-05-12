//Krishhhhh
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void bfs(ll n, ll m){
	// Creating a adj vector array
	vector<ll> adj[n+1];
	for(int i=0;i<m;i++){
		ll u,v;
		cin>>u>>v;
		adj[v].push_back(u);
		adj[u].push_back(v); // undirected graph
	}

	// Make pre req
	queue<ll> q;
	ll vis[n+1]={0};
	vector<ll> bfs;
	ll start=1;
	q.push(start);
	vis[1]=1;

	//BFS loop
	while(!q.empty()){
		ll node = q.front();
		bfs.push_back(node);
		q.pop();
		for(auto it : adj[node]){
			if(!vis[it]){
				vis[it]=1;
				q.push(it);
			}
		}
	}

	for(auto it : bfs){
		cout<<it<<" ";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m;
	cin>>n>>m;
	bfs(n);
}
