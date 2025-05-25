class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int ans = INT_MIN;
        for(int i = 0 ; i < n ; i ++){
            sum+=nums[i];
            if(sum<0){
                ans = max(ans , sum );
                sum = 0;
            }
            else{
                ans = max(ans , sum );
            }
        }
        return ans;
    }
};

// IF ASKED TO PRINT

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int ans = INT_MIN;
        int st = -1;
        int en = -1;
        for(int i = 0 ; i < n ; i ++){
            sum+=nums[i];
            if(sum<0){
                ans = max(ans , sum );
                sum = 0;
                st = i; // HERE
            }
            else{
                ans = max(ans , sum );
                en = i; // TO HERE
            }
        }
        return ans;
    }
};
