class Solution {
public:
    int findans(int ind1, int ind2, string& str1, string& str2, vector<vector<int>>& dp){
        if(ind1<0 || ind2<0) return 0;

        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

        if(str1[ind1] == str2[ind2]) return dp[ind1][ind2] = 1 + findans(ind1-1, ind2-1, str1, str2, dp);

        int one = findans(ind1-1, ind2, str1, str2, dp);
        int two = findans(ind1, ind2 - 1, str1, str2, dp);

        return dp[ind1][ind2] = max(one, two);
    }

    int longestPalindromeSubseq(string s) {
        string revs = "";
        int n = s.size();
        for(int i = n-1; i>=0 ; i--){
            revs+=s[i];
        }      

        vector<vector<int>> dp(n, vector<int> (n , -1));

        return findans(n-1, n-1, s, revs, dp);
    }
};

class Solution {
public:
    int findans(int ind1, int ind2, string& str1, string& str2, vector<vector<int>>& dp){
        if(ind1<0 || ind2<0) return 0;

        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

        if(str1[ind1] == str2[ind2]) return dp[ind1][ind2] = 1 + findans(ind1-1, ind2-1, str1, str2, dp);

        int one = findans(ind1-1, ind2, str1, str2, dp);
        int two = findans(ind1, ind2 - 1, str1, str2, dp);

        return dp[ind1][ind2] = max(one, two);
    }

    int longestPalindromeSubseq(string s) {
        string str1 = s;
        string str2 = "";
        int n = s.size();
        for(int i = n-1; i>=0 ; i--){
            str2+=str1[i];
        }      

        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));

        for(int i = 1 ; i <= n ; i ++){
            for(int j = 1 ; j <= n ; j++){
                if(str1[i-1] == str2[j-1]) dp[i][j] = 1 + dp[i - 1][j - 1];

                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n][n];
    }
};

