// User function Template for C++

class Solution {
  public:

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices) {
        // write your code here
        vector<int> ans;
        for(int i = 0 ; i < queries ; i ++){
            stack<int> st;
            int r = n - 1;
            while(r>=indices[i]){
                if(arr[indices[i]] < arr[r]){
                    st.push(arr[r]);
                }
                r--;
            }
            ans.push_back(st.size());
        }
        return ans;
    }
};
