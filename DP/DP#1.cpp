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

ll memo(ll &n){
	vector<ll> dp(n+1,-1);
	return f(n, dp);
}

// TC=O(N)                    SP = O(N)

// Now same solution in TABULATION - ( RECURSIVE TO TABULATION)

ll tabu(ll &n){
	vector<ll> dp(n+1, -1);
	dp[0]=0;
	dp[1]=1;
	for(int i=2;i<n+1;i++){
		dp[i]=dp[i-1]+dp[i-2];
	}
	return dp[n];
}

// TC = O(N)                   SP = O(N)

ll tabu_spaceoptimised(ll &n){
	ll prevv=0;
	ll prev =1;
	ll cur;

	for(int i=2; i<n+1 ; i++){
		cur = prevv + prev;
		prevv = prev;
		prev = cur;
		
	}
	return cur;
}
// TC = O(N)                   SP = O(1)


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	cout<<"MEMO:" << memo(n)<<endl;
	cout<<"TABU:" << tabu(n)<<endl;
	cout<<"TABU_OPT:" << tabu_spaceoptimised(n);
}


