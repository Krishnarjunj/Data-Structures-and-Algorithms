class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l = m - 1;
        int r = n - 1;
        int k = n + m - 1;
        if(n==0) return;
        while(l>=0 && r>=0){
            if(nums1[l]>nums2[r]){
                nums1[k] = nums1[l];
                k--;
                l--;
            }
            else{
                nums1[k] = nums2[r];
                k--;
                r--;
            }
        }
        while(r>=0){
            nums1[k--] = nums2[r--];
        }
    }
};
