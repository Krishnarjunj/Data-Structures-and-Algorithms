class Solution {
public:
    void reverse(vector<int> &nums, int p , int q){
        while(p <= q){
            swap(nums, p , q);
            p++;
            q--;
        }
    }

    void swap(vector<int> &nums, int p , int q){
        int temp = nums[p];
        nums[p] = nums[q];
        nums[q] = temp;
    }

    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = -2;
        int ele;
        for(int i = n-1 ; i >= 1 ; i --){
            if(nums[i]>nums[i-1]){
                ind = i-1;
                break;
            }
        }
        if(ind!=-2){
            for(int i = n-1; i > ind ; i--){
                if(nums[i] > nums[ind]){
                    swap(nums , i , ind);
                    break;
                }
            }
            reverse(nums , ind+1, n-1);
            
        }
        else{
            reverse(nums, 0 , n-1);
        }
        
    }
};
