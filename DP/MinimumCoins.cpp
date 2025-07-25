class Solution {
public:
    int findans(int ind, int sum, vector<int>& nums, vector<vector<int>>& dp){
        if(ind==0){
            if(sum%nums[ind]==0){
                return sum/nums[ind];
            }
            return INT_MAX;
        }

        if(dp[ind][sum]!=-1) return dp[ind][sum];

        //take
        int take = INT_MAX;
        if(nums[ind]<=sum){
            int calc = findans(ind, sum - nums[ind], nums, dp);
            if(calc!=INT_MAX) take = 1 + calc;
        }

        int nottake = findans(ind - 1, sum , nums, dp);

        return dp[ind][sum] = min(take, nottake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1 , -1));

        if(findans(n-1, amount, coins, dp)==INT_MAX) return -1;
        return findans(n-1, amount, coins, dp);
    }
};
