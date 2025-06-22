class Solution {
public:
    bool checkValidString(string s) {
        int minc = 0;
        int maxc = 0;
        int n = s.size();

        for(int i = 0 ; i < n ; i ++){
            if(s[i] == '('){
                minc++;
                maxc++;
            }
            else if(s[i] == ')'){
                minc--;
                maxc--;
            }
            else{
                maxc++;
                minc--;
            }
            if(minc<0) minc = 0;
            if(maxc < 0) return false;
        }

        if(0>=minc && 0<=maxc) return true;
        else return false;
    }
};
