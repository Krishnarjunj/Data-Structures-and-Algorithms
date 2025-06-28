class Solution {
  public:
    vector<int> leftSmaller(vector<int> arr) {
        // code here
        int n = arr.size();
        stack<int> st;
        vector<int> ans;
        for(int i = 0 ; i < n ; i ++){
            if(!st.empty()){
                if(st.top()<arr[i]){
                    ans.push_back(st.top());
                    st.push(arr[i]);
                }
                else{
                    while(!st.empty() && st.top()>=arr[i]){
                        st.pop();
                    }
                    if(!st.empty()){
                        ans.push_back(st.top());
                        st.push(arr[i]);
                    }
                    else{
                        st.push(arr[i]);
                        ans.push_back(-1);
                    }
                }
            }
            else{
                ans.push_back(-1);
                st.push(arr[i]);
            }
        }
        return ans;
    }
};
