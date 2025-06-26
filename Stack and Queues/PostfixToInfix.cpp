// User function Template for C++

class Solution {
  public:
    string postToInfix(string exp) {
        // Write your code here
        string s = exp;
        int n = exp.size();
        stack<string> st;
        for(int i = 0 ; i < n ; i++){
            string c(1,s[i]);
            if((c>="a" && c<="z") || (c>="A" && c<="Z") || (c>="0" && c<="9")){
                st.push(c);
            }
            else{
                string c2 = st.top();
                st.pop();
                string c1 = st.top();
                st.pop();
                string temp = "(" + c1 + c + c2 + ")";
                st.push(temp);
            }
        }
        string ans = st.top();
        return ans;
    }
};
