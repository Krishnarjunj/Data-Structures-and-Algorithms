class Solution {
  public:
    int twoddp(int day, int last, vector<vector<int>>& arr, vector<vector<int>>& dp){
        if(dp[day][last]!=-1) return dp[day][last];
        
        if(day == 0){
            int maxi = 0;
            for(int i = 0 ; i <3 ; i++){
                if(i!=last){
                    int activity = arr[day][i];
                    maxi = max(maxi, activity);
                }
            }
            return dp[day][last] = maxi;
        }
        
        int maxi = 0;
        for(int i = 0 ; i < 3 ; i ++){
            if(i!=last){
                int activity = arr[day][i] + twoddp(day-1, i, arr, dp);
                maxi = max(maxi, activity);
            }
        }
        return dp[day][last] = maxi;
    }

    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(4,-1));
        return twoddp(n-1, 3, arr, dp);
    }
};

