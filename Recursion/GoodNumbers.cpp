class Solution {
private:
    const int MOD = 1e9 + 7;
    long long int pow(long long int x, long long n){
        if(n==0) return 1;
        if(n<0){
            n = -1 * n;
            x = 1/x;
        }
        long long ans = 1;
        while(n!=0){
            if(n%2==0){
                x = (x * x)%MOD;
                n = n/2;
            }
            else{
                n = n - 1;
                ans = (ans * x)%MOD;
            }
        }
        return ans;
    }
public:
    int countGoodNumbers(long long n) {
        return (pow(5, (n+1)/2)*pow(4,n/2))%MOD;

    }
};
