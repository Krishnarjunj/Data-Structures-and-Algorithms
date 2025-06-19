class Solution {
public:
    bool check(vector<int> nums, int threshold, int num){
        long long int sum = 0;
        for(auto it : nums){
            sum += ceil((double)it/num);
        }
        if(sum <= threshold) return true;
        return false;
    }

    int findmax(vector<int> nums){
        int ans = INT_MIN;
        for(auto it: nums){
            ans = max(ans, it);
        }
        return ans;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int st = 1;
        int en = findmax(nums);

        while(st <= en){
            int mid = (st + en)/2;
            
            if(check(nums, threshold, mid)){
                en = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        return st;
    }
};
