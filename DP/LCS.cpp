class Solution {
public:
    int findans(int ind1, int ind2, string str1, string str2, vector<vector<int>>& dp){
        if(ind1<0 || ind2<0) return 0;

        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

        if(str1[ind1] == str2[ind2]) return dp[ind1][ind2] = 1 + findans(ind1-1, ind2-1, str1, str2, dp);

        int one = findans(ind1-1, ind2, str1, str2, dp);
        int two = findans(ind1, ind2 - 1, str1, str2, dp);

        return dp[ind1][ind2] = max(one, two);
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n , vector<int> (m , -1));

        return findans(n-1, m-1, text1, text2, dp);
        
    }
};

class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n , vector<int> (m , 0));

        for(int i = 0 ; i < n ; i ++){
            if(text1[i]==text2[0]) dp[i][0] = 1;
            else if(i>0) dp[i][0] = dp[i-1][0];
        }
        for(int i = 0 ; i < m ; i ++){
            if(text2[i]==text1[0]) dp[0][i] = 1;
            else if(i>0) dp[0][i] = dp[0][i-1];
        }

        for(int i = 1 ; i < n ; i ++){
            for(int j = 1; j < m ; j ++){
                if(text1[i]==text2[j]) dp[i][j] = 1 + dp[i-1][j-1];
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n-1][m-1];
        
    }
};
