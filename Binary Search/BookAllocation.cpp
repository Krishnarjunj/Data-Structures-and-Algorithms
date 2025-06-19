class Solution {
  public:
    
    int check(vector<int> arr, int num){
        int n = arr.size();
        int c = 1;
        long long int sum = 0;
        
        for(auto it : arr){
            if(sum + it > num){
                c++;
                sum = it;
            }
            else{
                sum+=it;
            }
        }
        return c;
        
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(k > n) return -1;
        int st = *max_element(arr.begin(), arr.end());
        int en = accumulate(arr.begin(), arr.end(), 0);
        
        while(st<=en){
            int mid = (st + en)/2;
            
            if(check(arr, mid) > k){
                st = mid + 1;
            }
            else{
                en = mid - 1;
            }
        }
        return st;
        
    }
};
