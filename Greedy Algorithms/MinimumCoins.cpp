// User function Template for C++

class Solution {
  public:
    vector<int> minPartition(int N) {
        // code here
        int curr = N;
        vector<int> coins = {2000, 500, 200, 100, 50, 20, 10 , 5, 2, 1 };
        vector<int> ans;
        for(int i = 0 ; i < 10 ; i++){
            while(curr>=coins[i]){
                ans.push_back(coins[i]);
                curr-=coins[i];
            }
        }
        return ans;
    }
};
