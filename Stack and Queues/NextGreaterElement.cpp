class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        stack<int> st;
        unordered_map<int,int> neg;
        for(int i = n-1; i >=0 ; i--){
            if(!st.empty()){
                if(st.top()>nums2[i]){
                    neg[nums2[i]] = st.top();
                    st.push(nums2[i]);
                }
                else{
                    while(!st.empty() && st.top()<=nums2[i]){
                        st.pop();
                    }
                    if(st.empty()){
                        neg[nums2[i]] = -1;
                        st.push(nums2[i]);
                    }
                    else{
                        neg[nums2[i]] = st.top();
                        st.push(nums2[i]);
                    }
                }
            }
            else{
                neg[nums2[i]] = -1;
                st.push(nums2[i]);
            }
        }

        vector<int> ans;
        for(int i = 0 ; i < nums1.size();i++){
            ans.push_back(neg[nums1[i]]);
        }
        return ans;
    }
};
