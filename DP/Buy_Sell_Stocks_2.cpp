class Solution {
public:
    int findans(int ind, int mode , vector<vector<int>>& dp, vector<int>& prices){
        if(ind == prices.size()) return 0; // we cant do anything

        if(dp[ind][mode]!=-1) return dp[ind][mode];

        int profit = INT_MIN;

        // buy mode
        if(mode == 0){
            // buyit now
            profit = max(profit, -prices[ind]+findans(ind + 1, 1 , dp, prices));
            // buy later
            profit = max(profit, findans(ind + 1, 0 , dp , prices));
        }
        //sell mode
        else{
            // sell now
            profit = max(profit, +prices[ind] + findans(ind + 1, 0 , dp , prices));
            // sell later
            profit = max(profit, findans(ind+1 , 1, dp, prices) );
        }

        return dp[ind][mode] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n , vector<int> (2, -1));

        return findans(0 , 0 , dp , prices);

    }
};


class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n+ 1, vector<int> (2, INT_MIN));

        // base
        dp[n][0] = 0;
        dp[n][1] = 0;

        for(int i = n-1 ; i >= 0 ; i --){
            for(int j = 0 ; j < 2 ; j ++){
                // buy
                int profit = INT_MIN;
                if(j == 0){
                    profit = max(0 + dp[i+1][0] , -prices[i] + dp[i + 1][1] );
                }
                else{
                    profit = max(0 + dp[i+1][1] , +prices[i] + dp[i+1][0]);
                }
                dp[i][j] = profit;
            }
        }

        return dp[0][0];

    }
};
