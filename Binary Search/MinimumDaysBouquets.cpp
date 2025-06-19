class Solution {
public:
    int check(vector<int> bloomday, int m , int k, int days){
        int n = bloomday.size();
        int ans = 0;
        int c = 0;
        for(int i = 0; i < n ; i ++){
            if(bloomday[i] - days <=0){
                c++;
                if(c==k){
                    c=0;
                    ans++;
                }
            }
            else{
                c=0;
            }
        }
        return ans;
    }

    int minday(vector<int> bloomDay){
        int ans = INT_MAX;
        for(auto it : bloomDay){
            ans = min(ans, it);
        }
        return ans;
    }

    int maxday(vector<int> bloomDay){
        int ans = INT_MIN;
        for(auto it : bloomDay){
            ans = max(ans, it);
        }
        return ans;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int st = minday(bloomDay);
        int n = bloomDay.size();
        int en = maxday(bloomDay);
        long long int prod = 1LL*m*k;

        while(st <= en){
            int mid = (st + en)/2;
            int flowers = check(bloomDay, m , k , mid);
            if(flowers >= m){
                en = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        if(prod > n){
            return -1;
        }
        return st;
    }
};
