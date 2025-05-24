//Krishhhhh
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll bruteforce(ll a[]){
	for(int i = 0 ; i < n ; i++){
		for(int j =0 ; j < i ; j++){
			sum+=[i]
		}
	}
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,k;
	cin>>n>>k;
	ll a[n];
	for(int i = 0 ; i<n;i++){
		cin>>a[i];
	}
	ll st = 0;
	ll en = 1;
	ll l = 0;
	ll sum = a[0] + a[1];
	while(st<=n-1 && en<=n-1){
			if(sum==k){
				l = max(l , en - st + 1);
				if(st+1<=n-1){
					sum = sum - a[st] + a[st+1];
				}
				st++;
			}
			else if (sum < k){
				if(en+1<=n-1){
					sum = sum + a[en+1];
				}
				en++;
			}
			else if(sum > k){
				if(st+1<=n-1){
					sum = sum - a[st] + a[st+1];
				}
				st++;
			}
	}
	cout<<l;

}
