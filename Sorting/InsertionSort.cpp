class Solution {
  public:
    // Please change the array in-place
    void insertionSort(vector<int>& arr) {
        // code here
        int n = arr.size();
        for(int i = 0 ; i < n -1 ; i ++){
            int j = i;
            while(j>=0 && arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                j--;
            }
        }
    }
};
