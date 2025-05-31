class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> st;
        int sum = 0;
        int count = 0;
        for(int i = 0 ; i < n; i++){
            sum+=nums[i];
            if(sum==k){
                count++;
            }
            int x = sum - k;
            count+=st[x];
            st[sum]++;
        }
        if(n>1) return count;
        else if(n==1 && nums[0]==k) return 1;
        else return 0;
    }
};
