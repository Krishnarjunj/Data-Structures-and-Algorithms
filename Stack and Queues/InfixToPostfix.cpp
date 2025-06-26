class Solution {
  public:
    int precedence(char s){
        if(s=='+' || s=='-') return 1;
        if(s=='*'|| s=='/') return 2;
        if(s=='^') return 3;
        return -1;
    }
    string infixToPostfix(string& s) {
        // code here
        int n = s.size();
        stack<char> st;
        string ans = "";
        for(int i = 0 ; i < n ; i++){
            if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
                ans+=s[i];
            }
            else if(s[i]=='(') st.push('(');
            else if(s[i]==')'){
                while(st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                while(!st.empty() && precedence(s[i])<=precedence(st.top())){
                    ans+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};
