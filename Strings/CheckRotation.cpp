class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        for(int i = 0 ; i < s.size() ; i++){
            string ans = "";
            ans = goal.substr(i, s.size()) + goal.substr(0, i);
            if(ans == s) return true;
        }
        return false;
    }
};
