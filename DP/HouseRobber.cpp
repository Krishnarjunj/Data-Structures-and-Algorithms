class Solution {
public:
    int solve(vector<int>& dp, vector<int>& nums, int n){
        if(n == 1) return dp[1] = nums[0];
        if(n == 2) return dp[2] = max(nums[0], nums[1]);
        if(dp[n] == -1) {
            dp[n] = max(solve(dp, nums, n - 1), solve(dp, nums, n - 2) + nums[n - 1]);
        }
        return dp[n];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        return solve(dp, nums, n);
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        dp[0] = 0;
        dp[1] = nums[0];
        dp[2] = max(nums[0], nums[1]);

        for(int i = 3 ; i <= n ; i ++){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);
        }

        return dp[n];
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        
        int prevv = nums[0];
        int prev = max(nums[0], nums[1]);
        int now = max(prev, prevv + nums[2]);


        for(int i = 3 ; i <= n ; i ++){
            now = max(prev, nums[i-1] + prevv);
            prevv = prev;
            prev = now;
        }
        return now;
    }
};

