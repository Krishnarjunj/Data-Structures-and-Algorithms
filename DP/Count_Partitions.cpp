class Solution {
  public:
    int countPartitions(vector<int>& arr, int d) {
        int total = 0;
        for(int x : arr) total += x;

        if((total + d) % 2 != 0 || (total + d) < 0) return 0;

        int target = (total + d) / 2;
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        
        // base case fix
        if (arr[0] == 0) dp[0][0] = 2;  // pick or not pick
        else dp[0][0] = 1;             // don't pick anything
        
        if (arr[0] != 0 && arr[0] <= target) dp[0][arr[0]] = 1;

        for(int i = 1; i < n ; i++){
            for(int j = 0; j <= target ; j++){
                int take = 0;
                if(arr[i] <= j) take = dp[i-1][j-arr[i]];
                int nottake = dp[i-1][j];
                dp[i][j] = take + nottake;
            }
        }
        
        return dp[n-1][target];
    }
};
