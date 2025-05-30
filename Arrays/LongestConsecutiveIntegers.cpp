class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for(int i = 0 ; i < n ; i++){
            st.insert(nums[i]);
        }
        int ans = INT_MIN;
        for(auto it : st){
            if(st.find(it-1)==st.end()){
                int x = it;
                int cnt = 1;
                while(st.find(x+1)!=st.end()){
                    cnt++;
                    x++;
                }
                ans = max(ans, cnt);
            }
        }
        if(n>0) return ans;
        else return 0;


    }
};
