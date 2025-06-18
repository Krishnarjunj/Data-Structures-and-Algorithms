class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int st = 0 ;
        int en = n - 1;
        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-2]!=nums[n-1]) return nums[n-1];
        while(st<=en){
            int mid = (st + en)/2;
            if(nums[mid]!=nums[mid+1] && nums[mid]!= nums[mid-1]){
                return nums[mid];
            }
            // RIGHT SIDE
            else if(mid%2 ==0 && nums[mid] == nums[mid+1] || mid%2==1 && nums[mid-1]==nums[mid]){
               st = mid + 1;
            }
            // LEFT SIDE
            else{
                en = mid - 1;
            }
        }
        return -1;
    }
};
