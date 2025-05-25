//Krishhhhh
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, k;
	cin>>n>>k;
	vector<ll> a(n);
	map<ll , ll> hash;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	ll sum = 0;
	ll maxLen = 0;

	for(ll i = 0 ; i < n ; i++){
		sum+=a[i];
		// hash[sum] = i;  THIS IS WRONG. {2 , 0 , 0 , 0 , 3} becomes {2, 3} instead of {2, 0}. 
		if( hash[sum].find() == hash.end()){
			hash[sum] = i;
		}
		if(sum==k){
			maxLen = max(maxLen , i+1);
		}
		ll rem = sum - k;
		if(hash.find(rem) != hash.end()){
			maxLen = max(maxLen , i - hash[rem]);
		}
	}

	cout<< maxLen;

}
