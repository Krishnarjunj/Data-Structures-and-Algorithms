class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        // Tabulation
        // 2 changing variables so 2 nested loops
        // Base conditionns
        // Copy recursion
        int n = val.size();
        vector<vector<int>> dp(n, vector<int> (W+1, 0));
        
        for(int i = wt[0]; i <= W ; i ++){
            dp[0][i] = val[0];
        }
        
        for(int i = 1 ; i < n ; i ++){
            for(int j = 0 ; j < W+1; j++){
                int notake = 0 + dp[i-1][j];
                int take = INT_MIN;
                if(j >= wt[i]) take = val[i] + dp[i-1][j-wt[i]];
                dp[i][j] = max(notake, take);
            }
        }
        return dp[n-1][W];
    }
};

class Solution {
  public:
  
    int findans(int ind, int W, vector<vector<int>>& dp, vector<int>& val, vector<int>& wt){
        if(ind == 0){
            if(W>=wt[0]) return val[0];
            return dp[0][W] = 0;
        }
        
        if(dp[ind][W]!=-1) return dp[ind][W];
        //take
        int take = INT_MIN;
        if(W>=wt[ind]){
            take = val[ind] + findans(ind - 1, W-wt[ind], dp, val, wt);
        }
        //not take
        int not_take = findans(ind - 1, W, dp , val , wt);
        
        
        return dp[ind][W] = max(take, not_take);
    }
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n , vector<int> (W + 1 , -1));
        
        return findans(n - 1, W, dp, val , wt);
    }
};
