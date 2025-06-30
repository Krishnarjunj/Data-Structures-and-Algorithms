class Solution {
  public:
    // Please change the array in-place
    void solve(vector<int>& arr, int n){
        if(n==arr.size()) return;
        int j = n;
        while(j>0 && arr[j]<arr[j-1]){
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }

        solve(arr, n + 1);
        
    }
    
    void insertionSort(vector<int>& arr) {
        // code here
        solve(arr, 0);
    }
};
