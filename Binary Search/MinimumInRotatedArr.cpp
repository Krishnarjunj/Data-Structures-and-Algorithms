class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int st = 0;
        int en = n - 1;
        int ans = INT_MAX;

        while(st <= en){
            int mid = (st + en)/2;
            // JUST STORE nums[st];
            if(nums[mid] >= nums[st]){
                ans = min(ans , nums[st]);
                st = mid + 1;
            }
            // STORE MID
            else{
                ans = min(ans, nums[mid]);
                en = mid - 1;
            }
        }
        return ans;
    }
};
