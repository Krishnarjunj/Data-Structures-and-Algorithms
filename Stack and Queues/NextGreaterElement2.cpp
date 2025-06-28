class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;

        for(int i = 2*n - 1; i >= 0; i--) {
            int num = nums[i % n];
            while(!st.empty() && nums[st.top()] <= num) {
                st.pop();
            }
            if(i < n) {
                if(!st.empty()) res[i] = nums[st.top()];
            }
            st.push(i % n);
        }
        return res;
    }
};
