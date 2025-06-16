//Krishhhhh FROG PROBLEM
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// memoization
int solve(int n , vector<int> &dp, vector<int> height, int k){
	if(dp[n]!=-1) return dp[n];
	if(n==0) return dp[n] = 0;
	int minen = INT_MAX;
	for(int i = 1 ; i <= k ; i ++){
		if(n-i>=0){
			int jump = solve(n - i, dp, height, k) + abs(height[n] - height[n-i]);
			minen = min(jump , minen);
		}
		
	}
	return dp[n] = minen;
}

// tabulation
int solvetab(int n, vector<int> height, int k){
	vector<int> dp(n+1, -1);
	dp[0] = 0;

	for(int i = 1 ; i <= n ; i++){
		int minen = INT_MAX;
		for(int j = 1 ; j <= k; j++){
			if(i-j >= 0){
				int jump = dp[i-j] + abs(height[i] - height[i-j]);
				minen=min(jump, minen);
				
			}
		}
		dp[i] = minen;
	}
	return dp[n];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k = 2;
	vector<int> height = {30, 10, 60, 10, 60, 50};
	int n = height.size()-1;
	vector<int> dp(n+1, -1);
	cout<<solvetab(n , height, k);
}
