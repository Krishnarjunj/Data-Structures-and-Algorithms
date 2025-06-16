//Krishhhhh FROG PROBLEM
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// memoization
int solve(int n , vector<int> &dp, vector<int> height){
	if(dp[n]!=-1) return dp[n];
	if(n==0) return dp[n] = 0;

	int jump1 = solve(n-1, dp , height) + abs(height[n] - height[n-1]);
	int jump2 = INT_MAX;
	if(n>1){
		int jump2 = solve(n-2, dp , height) + abs(height[n] - height[n-2]);
	}

	return dp[n] = min(jump1, jump2);
}

// tabulation
int solvetab(int n, vector<int> height){
	vector<int> dp(n+1, -1);
	dp[0] = 0;

	for(int i = 1 ; i <= n ; i++){
		int jump1 = dp[i-1] + abs(height[i] - height[i-1]);
		int jump2 = INT_MAX;
		if(n>1){
			jump2 = dp[i-2] + abs(height[i] - height[i-2]);
		}
		dp[i] = min(jump1, jump2);
	}
	return dp[n];
}

// space optimized 

int optimized(int n , vector<int> height){
	int prev = 0;
	int prev2 = 0;
	for(int i = 1 ; i <= n ; i++){
		int jump1 = prev + abs(height[i] - height[i-1]);
		int jump2 = INT_MAX;
		if(n>1){
			jump2 = prev2 + abs(height[i] - height[i-2]);
		}
		int cur_i = min(jump1, jump2);
		prev2 = prev; 
		prev = cur_i;
	}
	return prev;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> height = {30,10,60,10,60,50};
	int n = height.size()-1;
	vector<int> dp(n+1, -1);
	cout<<optimized(n , height);
}
