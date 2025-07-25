// User function Template for C++

class Solution {
  public:
    int findans(int ind, int W, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp){
        if(ind == 0){
            return (W/wt[0])*val[0];
        }
        
        if(dp[ind][W]!=-1) return dp[ind][W];
        
        //take
        int take = INT_MIN;
        if(W >=wt[ind]) take = val[ind] + findans(ind, W - wt[ind], val, wt, dp );
        
        int nottake = findans(ind - 1, W, val , wt, dp);
        
        return dp[ind][W] = max(take, nottake);
    }
  
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = wt.size();
        vector<vector<int>> dp(n , vector<int> (capacity + 1, -1));
        
        
        return findans(n-1, capacity, val, wt, dp);
    }
};

// User function Template for C++

class Solution {
  public:
  
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = wt.size();
        vector<vector<int>> dp(n , vector<int> (capacity + 1, 0));
        
        //base
        for(int i = wt[0] ; i <= capacity ; i ++){
            dp[0][i] = (i/wt[0])*val[0];
        }
        
        for(int i = 1; i < n ; i ++){
            for(int j = 0; j <= capacity; j++){
                int take = INT_MIN;
                if(j >=wt[i]) take = val[i] + dp[i][j-wt[i]];
                int nottake = dp[i-1][j];
                dp[i][j] = max(take, nottake);
            }
        }
        
        return dp[n-1][capacity];
    }
};
