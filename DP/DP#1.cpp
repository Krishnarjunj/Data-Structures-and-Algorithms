//DP 1 
//Krishhhhh
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll f(ll n, vector<ll> &dp){
	if(n==1 || n==0){
		return n;
	}
	else{
		if(dp[n]==-1){
			dp[n]=f(n-1, dp)+f(n-2, dp);
		}
		else{
			return dp[n];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	vector<ll> dp(n+1,-1);
	cout<<f(n, dp)<<endl;
}
