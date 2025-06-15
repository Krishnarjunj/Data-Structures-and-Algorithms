class Solution {
public:
    int steps(int n , vector<int> &dp){
        if(dp[n]!=-1) return dp[n];
        else{
            return dp[n] = steps(n-1, dp) + steps(n-2, dp);
        }
    }

    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        return steps(n , dp);
    }
};

class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        int cur_i = 0;
        int prev = 2;
        int prev2 = 1;
        for(int i = 2; i < n ; i++){
            cur_i = prev + prev2;
            prev2 = prev;
            prev = cur_i;
        }
        return cur_i;
    }
};
