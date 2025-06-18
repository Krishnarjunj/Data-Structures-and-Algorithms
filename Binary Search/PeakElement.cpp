class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        if(n==1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;
        int st = 1;
        int en = n - 2;

        while(st <= en){
            int mid = (st + en)/2;

            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            // Left side
            else if(nums[mid] > nums[mid - 1]){
                st = mid + 1;
            }
            // Right side
            else{
                en = mid - 1;
            }
        }
        return -1;
    }
};
