// User function Template for C++

class Solution {
  public:
    string postToPre(string post_exp) {
        // Write your code here
        int n = post_exp.size();
        stack<string> st;
        for(int i = 0 ; i < n ; i ++){
            string c(1, post_exp[i]);
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
        return st.top();
    }
};
