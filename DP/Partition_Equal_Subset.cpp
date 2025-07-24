class Solution {
public:
    bool findans(int ind, int sum , vector<int>& nums, vector<vector<int>>& dp){
        if(sum == 0) return true;
        if(ind == 0){
            if(nums[ind] == sum) return true;
            return false;
        }

        if(dp[ind][sum]!= -1) return dp[ind][sum];

        //take
        bool take = false;
        if(nums[ind] <= sum){
            take = findans(ind - 1, sum - nums[ind], nums, dp);
        }

        //not take
        bool nottake = findans(ind - 1, sum , nums, dp);

        return dp[ind][sum] = take || nottake;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(auto it : nums){
            sum += it;
        }
        vector<vector<int>> dp(n, vector<int> (sum + 1, -1));
        if(sum%2!=0) return false;

        return findans(n-1, sum/2, nums, dp);
    }
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // tabulation approach
        int n = nums.size();
        int sum = 0;
        for(auto it : nums){
            sum+=it;
        }

        if(sum%2!=0) return false;

        vector<vector<int>> dp(n, vector<int> ( sum + 1, 0));

        // base conditions. if sum is 0 return true;
        for(int i = 0 ; i < n ; i ++){
            dp[i][0] = 1;
        }

        // base condition 
        for(int i = 0 ; i < n ; i ++){
            dp[i][nums[i]] = 1; // where the nums[i] is equal to itself
        }

        // now we run 2 for loops. 
        for(int i = 1 ; i < n ; i ++){
            for(int j = 0 ; j <= sum ; j ++){
                //take
                bool take = false;
                if(nums[i] <= j){
                    take = dp[i - 1][j - nums[i]];
                }
                //not take
                bool nottake = dp[i- 1][j];
                dp[i][j] = take || nottake;
            }
        }

        return dp[n-1][sum/2];

    }
};

bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum % 2 != 0) return false;

    int target = sum / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for(int num : nums){
        for(int j = target; j >= num; j--){
            dp[j] = dp[j] || dp[j - num];
        }
    }

    return dp[target];
}
