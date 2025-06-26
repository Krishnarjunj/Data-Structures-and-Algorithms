// User function Template for C++

class Solution {
  public:
    int precedence(char s){
        if(s=='^') return 3;
        if(s=='+' || s=='-') return 1;
        if(s=='*' || s=='/') return 2;
        return -1;
    }
    string InfixtoPrefix(string& s) {
        // Write your code here
        reverse(s.begin(), s.end());
        int n = s.size();
        for(int i = 0 ; i < n ; i ++){
            if(s[i]=='(') s[i]=')';
            else if(s[i]==')') s[i]='(';
        }
        stack<char> st;
        string ans = "";
        for(int i = 0 ; i < n ; i ++){
            char c = s[i];
            if((c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9')){
                ans+=c;
            }
            else if(c=='(') st.push('(');
            else if(c==')'){
                while(st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                if(c=='^'){
                    while(!st.empty() && precedence(c)<=precedence(st.top())){
                        ans+=st.top();
                        st.pop();
                    }
                    st.push(c);
                }
                else{
                    while(!st.empty() && precedence(c)<precedence(st.top())){
                        ans+=st.top();
                        st.pop();
                    }
                    st.push(c);
                }
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};
