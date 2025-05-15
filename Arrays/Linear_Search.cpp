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

	ll q;
	cin>>q;
	bool ans = true;

	for(int i=0;i<n;i++){
		if(a[i] == q){
			cout<<"The element, "<<q<<" is at the index, "<<i<<" ."<<endl;
			ans = true;
			break;
		}
		else{
			ans = false;
		}
	}
	if(ans== false){
		cout<<-1;
	}



}
