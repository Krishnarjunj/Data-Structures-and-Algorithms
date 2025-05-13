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
	ll second_small;
	ll small = INT_MAX;
	ll second_large;
	ll large = INT_MIN;

	for(int i=0;i<n;i++){
		if(a[i]<small){
			second_small = small;
			small = a[i];
		}
		else if(second_small > a[i] && a[i]!=small){
			second_small = a[i];
		}

		if(a[i]>large){
			second_large = large;
			large = a[i];
		}
		else if(second_large < a[i] && large != a[i]){
			second_large = a[i];
		}
	}	
	cout<<second_small<< " " << second_large;
	
	// Time Complexity => O(N)

}
