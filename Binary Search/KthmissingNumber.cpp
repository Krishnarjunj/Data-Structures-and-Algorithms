class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int st = 0;
        int en = n - 1;

        while(st<=en){
            int mid = (st + en)/2;
            int missing = arr[mid] - mid - 1;
            if(missing >= k){
                en = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        return en + k + 1;
        
    }
};
