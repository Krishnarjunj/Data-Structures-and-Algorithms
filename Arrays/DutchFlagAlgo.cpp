//Krishhhhh
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void swap (vector<ll> &a , ll low , ll mid){
	ll temp = a[low];
	a[low] = a[mid];
	a[mid] = temp;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	vector<ll> a(n);
	for(int i = 0 ; i < n ; i ++){
		cin>>a[i];
	}
	ll low = 0;
	ll mid = 0;
	ll high = n-1;

	while(mid <= high){
		if(a[mid] == 0){
			swap(a, low , mid);
			low++;
			mid++;
		}
		else if(a[mid] == 1){
			mid++;
		}
		else{
			swap(a, mid , high);
			high--;
		}
	}
	for(auto it : a){
		cout<<it<<" ";
	}

}
