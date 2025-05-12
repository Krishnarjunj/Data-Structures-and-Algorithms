//Krishhhhh
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll bfs(queue<pair<ll,ll>> &q, vector<ll> &vis, vector<ll> adj[]){
	ll counts = 0;
	while(!q.empty()){
		ll i = q.front().first;
		ll j = q.front().second;
		q.pop();
		

		for(auto it : adj[i]){
			if(vis[it]==1 && j !=it){
				counts ++;
			}

			else{
				q.push({it, i});
				vis[it] = 1;
			}
		}

	}
	return counts;

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	// Insert the adj vector below
	ll n = 8+1; // insert total number of nodes
	vector<ll> adj[n];
	adj[1]={2,3};
	adj[2]={5,6};
	adj[3]={4,7};
	adj[5]={6};
	adj[7]={8};
	adj[4]={8};

	// -----------------------------------------------//
	ll count = 0;
	queue < pair < ll , ll > > q;
	q.push({1,1});
	vector<ll> vis(n,0);
	vis[1]=1;
	for(int i=0;i<n;i++){
		if(vis[i]!=1){
			count += bfs(q, vis, adj);
		}
	}

	cout<<count<<endl;

}
