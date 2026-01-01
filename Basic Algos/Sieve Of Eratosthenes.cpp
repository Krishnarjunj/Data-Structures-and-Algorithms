class Solution {
public:
    int countPrimes(int n) {
        if(n==1 || n==2) return 0;
        n--;  // leetcode asked for < and not <= thats y
        vector<bool> prime(n+1, true);
        for(int p = 2; p*p<=n ; p++){
            if(prime[p]==true){
                for(int i = p*p ; i <= n ; i+=p){
                    prime[i] = false;
                }
            }
            
        }
        int c = 0;
        for(int i = 2; i <=n ; i++){
            if(prime[i]) c++;
        }
        return c;
    }
};
