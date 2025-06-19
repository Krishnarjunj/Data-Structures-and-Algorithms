// User function Template for C++

class Solution {
  public:
    bool check(vector<int> stalls, int k, int num){
        int x = 1;
        int el = stalls[0];
        for(auto it : stalls){
            if(it - el >= num){
                x++;
                el = it;
            }
        }
        if(x>=k) return true;
        return false;
        
    }

    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        int n = stalls.size();
        sort(stalls.begin(), stalls.end());
        
        int st = 1;
        int en = stalls[n-1]-stalls[0];
        
        while(st<=en){
            int mid = (st + en)/2;
            
            if(check(stalls, k , mid)){
                st = mid + 1;
            }
            else{
                en = mid - 1;
            }
        }
        return en;
        
        
    }
};
