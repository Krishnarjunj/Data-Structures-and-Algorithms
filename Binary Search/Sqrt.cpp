class Solution {
public:
    int mySqrt(int x) {
        long long int st = 1;
        long long int en = x;

        while(st <= en){
            long long int mid =(double)(st + en)/2;
            long long int val = (double)mid*mid;

            if(val > x){
                en = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        return ceil(en);
    }
};
