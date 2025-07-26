class Solution {
public:
    string findans(int ind1, int ind2, string& str1, string& str2, vector<vector<string>>& dp){
        if(ind1<0 || ind2<0) return "";

        if(dp[ind1][ind2]!="-1") return dp[ind1][ind2];

        if(str1[ind1] == str2[ind2]) return dp[ind1][ind2] = findans(ind1-1, ind2-1, str1, str2, dp) + str1[ind1];

        string one = findans(ind1-1, ind2, str1, str2, dp);
        string two = findans(ind1, ind2 - 1, str1, str2, dp);

        if(one.size()>two.size()) return dp[ind1][ind2] = one;
        return dp[ind1][ind2] = two;
    }

    string longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<string>> dp(n , vector<string> (m , "-1"));

        return findans(n-1, m-1, text1, text2, dp);
        
    }
};

class Solution {
public:

    string longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<string>> dp(n , vector<string> (m , ""));

        for(int i = 0 ; i < n ; i ++){
            if(text1[i]==text2[0]) dp[i][0] = text1[i];
            else if(i>0) dp[i][0] = dp[i-1][0];
        }
        for(int i = 0 ; i < m ; i ++){
            if(text2[i]==text1[0]) dp[0][i] = text2[i];
            else if(i>0) dp[0][i] = dp[0][i-1];
        }

        for(int i = 1 ; i < n ; i ++){
            for(int j = 1; j < m ; j ++){
                if(text1[i]==text2[j]) dp[i][j] = dp[i-1][j-1] + text1[i];
                else{
                    if(dp[i-1][j].size() > dp[i][j-1].size()) dp[i][j] = dp[i-1][j];
                    else dp[i][j] = dp[i][j-1];
                }
            }
        }

        return dp[n-1][m-1];
        
    }
};
