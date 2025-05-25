class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c = 0;
        int el = nums[0];
        for(auto it: nums){
            if(c>0){
                if(it==el){
                c++;
                }
                else{
                    c--;
                }
            }
            else{
                el = it;
                c = 1;
            }
        }
        return el;
    }
};
