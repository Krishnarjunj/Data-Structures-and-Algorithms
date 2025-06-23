class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxrange = 1;
        for(int i = 0 ; i < n ; i++){
            if(i+1 > maxrange){
                return false;
            }
            maxrange = max(maxrange, i + 1 + nums[i]);
        }
        return true;
    }
};
