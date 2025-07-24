class Solution {
public:
    bool findans(int ind, int sum, vector<int>& nums, vector<vector<int>>& dp){
        if(sum == 0) return true;
        if(ind == 0){
            if(nums[ind]==sum) return true;
            return false;
        }

        if(dp[ind][sum]!=-1) return dp[ind][sum];

        //take 
        bool take = false;
        if(nums[ind]<=sum){
            take = findans(ind - 1, sum - nums[ind], nums, dp);
        }

        //nottake
        bool nottake = findans(ind - 1, sum, nums, dp);

        return dp[ind][sum] = take || nottake;
    }

    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for(auto it : nums) sum+=it;
        vector<vector<int>> dp(n , vector<int> (sum+1, -1));

        for(int i = 0 ; i <= sum ; i ++){
            bool dummy = findans(n-1, i , nums, dp);
        }

        int ans = INT_MAX;

        for(int i = 0 ; i <= sum ; i ++){
            if(dp[n-1][i]){
                ans = min(ans, sum - 2*i);           
            }
        }

        return ans;

    }
};

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for(auto it : nums) sum+=it;
        vector<vector<int>> dp(n , vector<int> (sum+1, 0));

        // base
        for(int i = 0 ; i < n ; i++){
            dp[i][0] = 1;
        }
        if(nums[0] <= sum) dp[0][nums[0]] = 1;

        for(int i = 1 ; i < n ; i ++){
            for(int j = 1 ; j <= sum ; j++){
                //take
                int take = 0;
                if(nums[i]<=j) take = dp[i-1][j-nums[i]];
                //nottake
                int nottake = dp[i-1][j];
                dp[i][j] = take || nottake;
            }
        }

        int ans = INT_MAX;

        for(int i = 0 ; i <= sum ; i ++){
            if(dp[n-1][i]){
                ans = min(ans, sum - 2*i);           
            }
        }

        return ans;

    }
};
