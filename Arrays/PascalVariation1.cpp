//Krishhhhh
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int ncr(ll r, ll c){
	ll res = 1;
	for(int i = c ; i >=1 ; i--){
		res = res * (r + i - c);
		res = res / (i);
	}
	return res;

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll r, c;
	cin>>r>>c;
	cout<< ncr(r-1, c-1);
}
