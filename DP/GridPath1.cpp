class Solution {
public:
    int countways(int i , int j , vector<vector<int>> &dp){
        if(i==0 && j==0) return 1;

        if(i<0 || j<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int up = countways(i-1 , j , dp);
        int right = countways(i, j-1, dp);
        return dp[i][j] = up + right;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n , vector<int> (m , -1));
        return countways(n-1 , m-1 , dp);

    }
};
