class Solution {
  public:
  
    void solve(vector<int>& arr, int st, int mid, int en){
        int l = st;
        int r = mid + 1;
        vector<int> temp;
        
        while(l<=mid && r<=en){
            if(arr[l]<arr[r]){
                temp.push_back(arr[l]);
                l++;
            }
            else{
                temp.push_back(arr[r]);
                r++;
            }
        }
        while(l<=mid){
            temp.push_back(arr[l]);
            l++;
        }
        while(r<=en){
            temp.push_back(arr[r]);
            r++;
        }
        for(int i = st ; i <= en ; i++){
            arr[i] = temp[i-st];
        }
        
    }
    void merge(vector<int>& arr, int st, int en){
        if(st>=en) return;
        int mid = (st + en)/2;
        merge(arr, st, mid);
        merge(arr, mid + 1, en);
        solve(arr, st, mid, en);
    }
    
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        int n = arr.size();
        merge(arr, 0 , n-1);
        
    }
};
