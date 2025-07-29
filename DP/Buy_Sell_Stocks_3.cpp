class Solution {
public:

    int findans(int ind, int mode , int k , vector<vector<vector<int>>>& dp , vector<int>& prices){
        //base
        if(k==2 || ind == prices.size()) return 0;
        
        if(dp[ind][mode][k]!=-1) return dp[ind][mode][k];

        int profit = INT_MIN;

        if(mode == 0){
            profit = max(-prices[ind] + findans(ind + 1 , 1 , k , dp , prices), findans(ind + 1, 0 , k , dp , prices));
        }
        else{
            profit = max(+prices[ind] + findans(ind + 1, 0 , k + 1, dp , prices), findans(ind + 1, 1, k , dp , prices));
        }

        return dp[ind][mode][k] = profit;
        
        }


    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n , vector<vector<int>> (2, vector<int>(3, -1)) );

        return findans(0, 0, 0, dp , prices);
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, 0)));

        for(int i = n-1 ; i >= 0 ; i--) {
            for(int j = 0 ; j < 2 ; j++) {
                for(int k = 0 ; k <= 2 ; k++) {
                    if(j == 0) { // Buy
                        dp[i][j][k] = max(-prices[i] + dp[i+1][1][k], dp[i+1][0][k]);
                    } else { // Sell
                        if(k < 2)
                            dp[i][j][k] = max(prices[i] + dp[i+1][0][k+1], dp[i+1][1][k]);
                        else
                            dp[i][j][k] = dp[i+1][1][k];
                    }
                }
            }
        }

        return dp[0][0][0]; // start from day 0, in buy mode, 0 transactions done
    }
};
