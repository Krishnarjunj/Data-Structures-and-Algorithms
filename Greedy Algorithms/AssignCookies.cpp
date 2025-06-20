class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int n1 = g.size();
        int n2 = s.size();
        int curg = 0;
        int curs = 0;
        int ans = 0;

        while(curg < n1 && curs < n2){
            if(g[curg] > s[curs] ){
                curs++;
            }
            else{
                curg++;
                curs++;
                ans++;
            }
        }
        return ans;
    }
};
