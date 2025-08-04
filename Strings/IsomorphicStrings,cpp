class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        unordered_map<char, bool> mpp;
        for(char i = 'a' ;  i <= 'z' ; i ++){
            mpp[i] = false;
        }
        int n = s.size();

        for(int i = 0 ; i < n ; i ++){
            if(!mpp[t[i]]){
                mp[s[i]] = t[i];
                mpp[t[i]] = true;
            }
        }

        string ans = "";

        for(int i = 0 ; i < n ; i ++){
            ans += mp[s[i]];
        }

        if(ans == t) return true;
        return false;
    }
};
