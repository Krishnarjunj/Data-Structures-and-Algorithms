class Solution {
public:
    int minpath(int i ,int ind, vector<vector<int>>& dp , vector<vector<int>>& triangle){
        if(i==0 && ind ==0) return triangle[0][0];  
        if(ind<0 || ind>=triangle[i].size()) return INT_MAX;
        if(dp[i][ind] != -1) return dp[i][ind];

        int left = minpath(i-1, ind-1, dp, triangle);
        int right = minpath(i-1, ind, dp, triangle);
        return dp[i][ind] = triangle[i][ind] + min(left, right);
    }


    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n);
        for(int i = 0; i < n; i++) {
            dp[i] = vector<int>(triangle[i].size(), -1);
        }
        int ans = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            ans = min(ans , minpath(n - 1,i,dp,triangle));
        }
        return ans;
    }
};
