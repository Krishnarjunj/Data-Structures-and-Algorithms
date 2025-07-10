class Solution {
public:
    int minsum(int i , int j , vector<vector<int>>& dp, vector<vector<int>>& grid){
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];

        int up = minsum(i-1, j, dp , grid);
        int left = minsum(i , j-1, dp, grid);
        
        return dp[i][j] = grid[i][j] + min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m , vector<int>(n,-1));
        return minsum(m-1, n-1, dp, grid);
    }
};
