class Solution {
  public:
    // Function to sort the array using bubble sort algorithm.
    void solve(vector<int>& arr, int n){
        for(int i = 0 ; i < n - 1; i ++){
            if(arr[i]>arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
        if(n>0){
            solve(arr, n - 1);
        }
    }
    
    void bubbleSort(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        solve(arr, n);
    }
};
