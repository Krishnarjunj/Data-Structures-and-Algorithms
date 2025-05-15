typedef int ll;
class Solution {

private:
    void reverse(vector<ll>& arr, ll st, ll ed){
        while(st <= ed){
            ll temp = arr[st];
            arr[st] = arr[ed];
            arr[ed] = temp;
            st++;
            ed--;
        }
    }

public:
    void rotate(vector<int>& nums, int k) {
        ll n = nums.size();
        if(k<=n){
            reverse(nums, 0 , nums.size()-1);
            reverse(nums, 0, k-1);
            reverse(nums, k, n-1);
        }
        else{
            k = k%n;
            reverse(nums, 0 , nums.size()-1);
            reverse(nums, 0, k-1);
            reverse(nums, k, n-1);
        }

    }
};
