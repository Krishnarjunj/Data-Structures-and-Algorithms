class Solution {
public:
    int countways(int i, int j, vector<vector<int>>& dp){
        if(i==0 && j==0 && dp[i][j]!=-2) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1 && dp[i][j]!=-2) return dp[i][j];
        if(dp[i][j]==-2) return 0;
        int up = countways(i-1, j , dp);
        int right = countways(i , j-1, dp);
        return dp[i][j] = up + right;

    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m , vector<int>(n, -1));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j ++){
                if(obstacleGrid[i][j]==1) dp[i][j] = -2;
            }
        }
        return countways(m-1, n-1, dp);
    }
};
