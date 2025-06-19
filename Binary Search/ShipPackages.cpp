class Solution {
public:
    bool check(vector<int> weights, int days, int num){
        int c = 1;
        long long int sum = 0;
        for(auto it : weights){
            if(sum + it > num){
                c++;
                sum = it;
            }
            else{
                sum+= it;
            }
        }

        if(c <= days) return true;
        return false;
    }
    int findsum(vector<int> weights){
        long long int ans = 0;
        for(auto it : weights){
            ans += it;
        }
        return ans;
    }

    int findmax(vector<int> weights){
        int ans = INT_MIN;
        for(auto it : weights){
            ans = max(ans, it);
        }
        return ans;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int st = findmax(weights);
        int en = findsum(weights);

        while(st<=en){
            int mid = (st + en)/2;
            if(check(weights, days, mid)){
                en = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        return st;
    }
};
