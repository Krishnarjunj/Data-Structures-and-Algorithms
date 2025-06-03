//Krishhhhh
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	n --;
	cout<< 1 << " ";
	ll ans = 1;

	for(int i = 1; i < n; i ++){
		ans = ans * (n - i);
		ans = ans / i;
		cout<< ans << " ";
	}
}
