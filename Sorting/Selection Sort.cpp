class Solution {
  public:
    // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &arr) {
        // code here
        int n = arr.size();
        for(int i = 0 ; i < n ; i ++){
            int ind = i;
            for(int j = i ; j < n ; j ++){
                if(arr[j]<arr[ind]){
                    ind = j;
                }
            }
            int temp = arr[i];
            arr[i] = arr[ind];
            arr[ind] = temp;
        }
    }
};
