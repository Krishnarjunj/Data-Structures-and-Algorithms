class Solution {
public:
    int findmax(vector<int> piles){
        int ans = INT_MIN;
        for(auto it : piles){
            ans = max(ans, it);
        }
        return ans;
    }

    long long int ttlhrs(vector<int> piles, int num){
        long long int ans = 0;
        for(auto it : piles){
            ans += (it +num - 1)/num;
        }
        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int st = 1;
        long long int en = findmax(piles);

        while(st <= en){
            long long int mid = (st + en)/2;
            long long int hrs = ttlhrs(piles, mid);
            if(h >= hrs){
                en = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        return st;
    }
};
