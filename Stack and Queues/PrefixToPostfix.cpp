// User function Template for C++

class Solution {
  public:
    string preToPost(string pre_exp) {
        reverse(pre_exp.begin(), pre_exp.end());
        int n = pre_exp.size();
        stack<string> st;
        for(int i = 0 ; i < n ; i ++){
            string c(1, pre_exp[i]);
            if((c>="a" && c<="z") || (c>="A" && c<="Z") || (c>="0" && c<="9")){
                st.push(c);
            }
            else{
                string t2 = st.top();
                st.pop();
                string t1 = st.top();
                st.pop();
                string temp = c + t1 + t2;
                st.push(temp);
            }
        }
        string ans = st.top();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
