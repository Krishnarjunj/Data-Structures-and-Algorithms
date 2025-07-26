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

    string longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n , vector<int> (m , -1));

        string ans = "";
        int length = findans(n-1, m-1, text1, text2, dp);

        for(int i = 0 ; i < length; i++){
            ans+="$";
        }

        int index = length - 1;
        int i = n - 1;
        int j = m - 1;

        while(i>=0 && j>=0){
            if(text1[i] == text2[j]){
                ans[index] = text1[i];
                i--;
                j--;
                index--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
        return ans;
        
    }
};
