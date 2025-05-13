//Krishhhhh
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	ll a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	ll ans = INT_MIN;

	for(int i=0;i<n;i++){
		ans = max(ans, a[i]);
	}

	cout<<ans;

	// Time Complexity => O(N)

}
