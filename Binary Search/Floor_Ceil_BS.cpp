//Krishhhhh
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int floor(vector<int> a, int k){
      int low = 0;
      int ans;
      int high = a.size() - 1;
      while(low <= high){
            int mid = (high + low)/2;
            if(a[mid] <= k){
                  ans = mid;
                  low = mid + 1;
            }
            else high = mid - 1;
      }
      return a[ans];
}

int ceil(vector<int> a, int k){
      int low = 0 ; 
      int high = a.size() -1;
      int ans = a.size() - 1;
      while(low <= high){
            int mid = (low + high)/2;
            if(a[mid] >= k){
                  ans = mid;
                  high = mid - 1;
            }
            else low = mid + 1;
      }
      return a[ans];
}


int main(){
      int n, target;
      cin>>n>>target;
      vector<int> nums(n);
      for(int i = 0 ; i < n ; i ++){
            cin>>nums[i];
      }
      cout << floor(nums, target) << " " << ceil(nums , target) ;
}
