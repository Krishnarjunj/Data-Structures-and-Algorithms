//Krishhhhh
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(ll n , ll a[]){
	ll temp = a[0];

	for(int i=0;i<n-1;i++){
		a[i] = a[i+1];
	}
	a[n-1] = temp;

	for(int i=0;i<n;i++){
		cout<<a[i]<< " ";
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	ll a[n];

	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	solve(n , a);

}
