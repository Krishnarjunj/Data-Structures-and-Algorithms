// User function Template for C++

class Solution {
  public:
    int findans(int ind, int l, vector<int>& price, vector<int>& length, vector<vector<int>>& dp){
      if(ind == 0){
        return (price[0]*l);
      }

      if(dp[ind][l]!=-1) return dp[ind][l];

      //nottake
      int nottake = 0 + findans(ind - 1, l , price, length, dp );

      //take
      int take = INT_MIN;
      if(l >= length[ind]) take = price[ind] + findans(ind, l - length[ind], price, length, dp);

      return dp[ind][l] = max(nottake, take);
    }

    int cutRod(vector<int> &price) {
      int n = price.size();

      // price = 1 5 8 9 10 17 17 20
      // length = 8
      // length = [1 , 2 , 3 , 4, 5, 6, 7, 8]
      // price = [1, 5, 8, 9, 10, 17, 17, 20]
      // this is like unbounded knapsack. initial weight being W
      // here its n
      vector<int> length(n);
      for(int i = 0 ; i < n ; i++){
        length[i] = i + 1;
      }

      vector<vector<int>> dp(n , vector<int> (n + 1 , -1));

      return findans(n-1, n , price, length, dp);
        
    }
};
