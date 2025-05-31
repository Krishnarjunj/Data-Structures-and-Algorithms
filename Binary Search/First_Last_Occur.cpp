//Krishhhhh
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int firstoccur(vector<int> nums, int k){
      int low = 0;
      int high = nums.size() - 1;
      int ans;

      while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid]==k){
                  ans = mid;
                  high = mid - 1;
            }
            else if(nums[mid] > k){
                  high = mid - 1;
            }
            else low = mid + 1;
      }
      return ans;
}

int lastoccur(vector<int> nums, int k){
      int low = 0;
      int high = nums.size() - 1;
      int ans;

      while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid]==k){
                  ans = mid;
                  low = mid + 1;
            }
            else if(nums[mid] > k){
                  high = mid - 1;
            }
            else low = mid + 1;
      }
      return ans;
}



int main(){
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      int n,k;
      cin>>n>>k;
      vector<int> nums(n);

      for(int i = 0 ; i < n ; i++){
            cin>>nums[i];
      }

      cout<< lastoccur(nums, k) - firstoccur(nums, k) + 1;

}
