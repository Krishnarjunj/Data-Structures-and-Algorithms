class Solution {
public:
    int findans(int ind, int mode, int t, int k , vector<vector<vector<int>>>& dp, vector<int>& prices){
        if(t == k || ind == prices.size()) return 0;

        if(dp[ind][mode][t]!=-1) return dp[ind][mode][t];

        if(mode == 0){
            return dp[ind][mode][t] = max(0 + findans(ind+1, 0, t, k, dp, prices), -prices[ind] + findans(ind+1, 1, t, k, dp, prices));
        }
        
        return dp[ind][mode][t] = max(0 + findans(ind+1, 1, t, k, dp, prices), prices[ind] + findans(ind+1, 0, t+1, k, dp, prices));
        
        
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (k+1, -1)));
        
        return findans(0, 0, 0, k, dp, prices);
    }
};

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (k+1, 0)));

        for(int i = n - 1; i >= 0 ; i --){
            for(int j = 0 ; j <= 1 ; j ++ ){
                for(int t = 0 ; t < k ; t ++){
                    if(j==0){
                        dp[i][0][t] = max(0 + dp[i+1][0][t], -prices[i] + dp[i+1][1][t]);
                    }
                    else{
                        dp[i][1][t] = max(dp[i+1][1][t], prices[i] + dp[i+1][0][t+1]);
                    }
                }
            }
        }

        return dp[0][0][0];
    }
};
