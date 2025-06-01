class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0;
        int en = n - 1;

        while(st <= en){
            int mid = (st + en)/2;

            if(nums[mid] == target) return true;
            
            if(nums[st] == nums[mid] && nums[mid] == nums[en]){
                st++;
                en--;
                continue;
            }

            
            
            // RIGHT SORTED
            else if(nums[mid] <= nums[en]){
                //target is present
                if(nums[mid] < target && target <= nums[en]){
                    st = mid + 1;
                }
                // Not present
                else{
                    en = mid - 1;
                }
            }
            // LEFT SORTED
            else{
                //target present
                if(target >= nums[st] && target < nums[mid]){
                    en = mid - 1;
                }
                // Not present
                else{
                    st = mid + 1;
                }
            }
        }
        return false;

    }
};
