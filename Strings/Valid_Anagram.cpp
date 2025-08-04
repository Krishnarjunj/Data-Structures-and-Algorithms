class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> ms;
        unordered_map<char, int> mt;
        int n = s.size();
        if(n != t.size()) return false;
        for(int i = 0 ; i < n ; i ++){
            ms[s[i]]++;
            mt[t[i]]++;
        }
        for(int i = 0 ; i < n ; i ++){
            if(ms[s[i]] != mt[s[i]]) return false;
        }

        return true;
    }
};
