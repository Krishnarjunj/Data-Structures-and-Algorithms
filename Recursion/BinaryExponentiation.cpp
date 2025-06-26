class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        double ans = 1.0;
        if(N<0){
            N = -1*N;
            x = 1/x;
        }
        while(N!=0){
            if(N%2==0){
                x = x * x;
                N = N/2;
            }
            else{
                N = N - 1;
                ans = ans * x;
            }
        }
        return ans;
    }
};
