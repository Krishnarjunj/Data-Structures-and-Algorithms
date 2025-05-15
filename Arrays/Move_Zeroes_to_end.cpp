typedef long long int ll;
class Solution {
private:
    void swap(vector<int> &arr, ll x, ll y){
        ll temp = arr[x];
        arr[x] = arr[y];
        arr[y] = temp;
    }
public:
    void moveZeroes(vector<int>& nums) {
        ll n = nums.size();
        if(nums.size()>1){
                ll p1 = 0;
                ll p2 = 1;
                while(p1 < n && p2 < n){
                    if(nums[p1] == 0 && nums[p2]!=0){
                        swap(nums, p1, p2);
                        p1++;
                        p2++;
                    }
                    else if(nums[p1]!=0 && nums[p2]!=0){
                        p1++;
                        p2++;
                    }
                    else if(nums[p1]!=0 && nums[p2]==0 ){
                        p1++;
                        p2++;
                    }
                    else{
                        p2++;
                    }
                }
        }

    }
};
