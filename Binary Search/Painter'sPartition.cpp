// User function template for C++

class Solution {
  public:
    int check(vector<int> arr, int num){
        long long int sum = 0;
        int c = 1;
        for(auto it : arr){
            if(sum + it > num){
                sum = it;
                c++;
            }
            else{
                sum += it;
            }
        }
        return c;
    }
  
    int minTime(vector<int>& arr, int k) {
        // code here
        int st = *max_element(arr.begin(), arr.end());
        int en = accumulate(arr.begin(), arr.end(), 0);
        
        while(st <= en){
            int mid = (st + en)/2;
            if(check(arr, mid) > k){
                st = mid + 1;
            }
            else en = mid - 1;
        }
        return st;
        // return minimum time
    }
};
