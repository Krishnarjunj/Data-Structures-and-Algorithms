class Solution {
  public:
    int check(long long int mid, int n, int m){
        long long int ans = 1;
        
        for(int i = 0 ; i < n ; i ++){
            ans *= mid;
            if(ans > m){
                return 0;
            }
        }
        if(ans==m) return 1;
        return 2;
        
    }
    int nthRoot(int n, int m) {
        // Code here.
        int st = 1;
        int en = m;
        
        while( st <= en){
            long long int mid = (st + en)/2;
            int ans = check(mid, n, m);
            if(ans == 1){
                return mid;
            }
            else if(ans == 0){
                en = mid - 1;
            }
            else st = mid + 1;
        }
        return -1;
    }
};
