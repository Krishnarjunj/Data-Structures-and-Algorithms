class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans;
        for(int i = 0; i < n ; i++){
            if(i != nums[i]){
                ans = i;
                break;
            }
        }
        return ans;
    }
};
