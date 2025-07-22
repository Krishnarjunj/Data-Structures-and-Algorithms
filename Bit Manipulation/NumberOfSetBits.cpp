class Solution {
public:
    int hammingWeight(int n) {
        int temp = n;
        int ans = 1;
        while(temp>1){
            if(temp%2!=0) ans++;
            temp/=2;
        }   
        return ans;
    }
};
