class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        int c=0;
        string ans = "";
        for(int i = 0 ; i < n ; i ++){
            if(s[i] == '('){
                c++;
                if(c > 1){
                    ans+='(';
                }
            }
            else if(s[i]==')'){
                c--;
                if(c >= 1){
                    ans+=')';
                }
            }
        }
        return ans;
    }
};
