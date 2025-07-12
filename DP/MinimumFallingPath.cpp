class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m , vector<int> (n, -1));

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i==0){
                    dp[0][j] = matrix[0][j];
                }
                else{
                    int left = INT_MAX;
                    int right = INT_MAX;
                    int mid = INT_MAX;
                    if(j > 0){
                        left = dp[i-1][j-1];
                    }
                    if(j<n-1){
                        right = dp[i-1][j+1];
                    }
                    mid = dp[i-1][j];
                    dp[i][j] = matrix[i][j] + min(left, min(right, mid));
                }
            }
        }
        int ans = INT_MAX;
        for(int i = 0 ; i < n ; i ++){
            ans = min(ans , dp[m-1][i]);
        }
        return ans;
    }
};
