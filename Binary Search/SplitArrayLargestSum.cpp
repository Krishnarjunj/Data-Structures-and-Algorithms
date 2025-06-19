class Solution {
public:
    int check(vector<int> nums, int num){
        long long int sum = 0;
        int c = 1;
        for(auto it : nums){
            if(sum + it > num){
                c++;
                sum = it;
            }
            else{
                sum+=it;
            }
        }
        return c;
    }
    int splitArray(vector<int>& nums, int k) {
        int st = *max_element(nums.begin(), nums.end());
        int en = accumulate(nums.begin(), nums.end(), 0);

        while(st <= en){
            int mid = (st + en)/2;

            if(check(nums, mid) > k){
                st = mid + 1;
            }
            else en = mid - 1;
        }
        return st;
        
    }
};
