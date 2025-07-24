class Solution {
  public:
  
    int findans(int ind, int sum , vector<int>& nums, vector<vector<int>>& dp){
        if(ind == 0){
            if(sum == 0 && nums[0] == 0) return 2; // take or not take
            if(sum == 0 || nums[0] == sum) return 1;
            return 0;
        }

        
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        
        // take
        int take = 0;
        if(nums[ind]<=sum) take = findans(ind - 1, sum - nums[ind], nums, dp);
        
        //not take
        int nottake = findans(ind - 1, sum , nums, dp);
        
        return dp[ind][sum] = take + nottake;
    }
  
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp (n , vector<int> (target + 1, -1));
        
        return findans(n - 1, target , arr, dp);
        
    }
};
