class Solution {
  public:
    
    bool findans(int ind, int target, vector<int>& arr, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(ind == 0) return arr[0] == target;
        
        if(dp[ind][target]!=-1) return dp[ind][target];
        
        bool NotTaken = findans(ind-1, target, arr, dp);
        
        bool taken;
        if(arr[ind]>target) taken = false;
        else taken = findans(ind - 1, target - arr[ind], arr, dp);
        
        return dp[ind][target] = (taken || NotTaken);
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n , vector<int> (sum+1 , -1));
        return findans(n-1, sum , arr, dp);
    }
};
