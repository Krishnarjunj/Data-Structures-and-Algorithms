class Solution {
public:
    int findans(int ind, int mode, vector<vector<int>>& dp, vector<int>& prices){
        if(ind >= prices.size() ) return 0;

        if(dp[ind][mode]!=-1) return dp[ind][mode];

        if(mode == 0){
            return dp[ind][mode] = max(0 + findans(ind+1, 0, dp, prices), -prices[ind]+findans(ind+1, 1, dp, prices));
        }
        return dp[ind][mode] = max(findans(ind+1,1,dp,prices), prices[ind]+findans(ind+2, 0, dp, prices));
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n+1, vector<int> (2, -1));

        return findans(0, 0, dp, prices);
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int> (2, 0));

        for(int i = n-1 ; i>=0 ; i--){
            for(int j = 0 ; j < 2 ; j ++){
                if(j==0){
                    dp[i][j] = max(dp[i+1][j], -prices[i]+dp[i+1][1]);
                }
                else{
                    dp[i][j] = max(dp[i+1][j], prices[i] + dp[i+2][0]);
                }
            }
        }

        return dp[0][0];      
    }
};
