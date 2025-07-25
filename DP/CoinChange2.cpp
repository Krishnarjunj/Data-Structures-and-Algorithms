class Solution {
public:
    int findans(int ind, int sum, vector<int>& coins, vector<vector<int>>& dp){
        if(ind == 0){
            if(sum%coins[0]==0) return 1;
            return 0;
        }
        
        if(dp[ind][sum]!=-1) return dp[ind][sum];

        //take
        int take = 0;
        if(coins[ind]<=sum) take = findans(ind, sum - coins[ind], coins, dp);

        int nottake = findans(ind - 1, sum, coins, dp);

        return dp[ind][sum] = take + nottake;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n , vector<int> (amount+1, -1));

        return findans(n-1, amount, coins, dp);
        
    }
};
