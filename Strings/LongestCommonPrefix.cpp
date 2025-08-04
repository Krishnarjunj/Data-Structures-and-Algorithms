class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int s = INT_MAX;
        string ele;
        for(auto it : strs){
            if(s > it.size()){
                ele = it;
                s = it.size();
            }
        }
        char e;
        string ans = "";

        for(int i = 0 ; i < s ; i ++){
            e = ele[i];
            for(auto it : strs){
                if(it[i] != e) {
                    return ans; 
                }
            }
            ans += e;
        }
        return ans;
    }
};
