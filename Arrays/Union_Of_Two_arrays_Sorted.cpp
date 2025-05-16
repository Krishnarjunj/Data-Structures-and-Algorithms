//Krishhhhh
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> Union_Using_Freq(vector<ll> arr, vector<ll> brr){
	ll n = arr.size();
	ll m = brr.size();
	map < ll , ll > freq;
	for(int i =0; i<n ; i++){
		freq[arr[i]]++;
	}
	for(int i=0;i<m;i++){
		freq[brr[i]]++;
	}
	vector<ll> ans;
	for(auto it : freq){
		ans.push_back(it.first);
	}
	return ans;
}

vector<ll> Union_Using_Set(vector<ll> arr, vector<ll> brr){
	ll n = arr.size();
	ll m = brr.size();
	set<ll> s;

	for(int i=0;i<n;i++){
		s.insert(arr[i]);
	}
	for(int i=0;i<m;i++){
		s.insert(brr[i]);
	}
	vector<ll> ans;
	for(auto it : s){
		ans.push_back(it);
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m;
	cin>>n>>m;
	vector<ll> a(n);
	vector<ll> b(m);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		cin>>b[i];
	}
	a = Union_Using_Set(a, b);

	for(auto it : a){
		cout<< it<< " ";
	}
	

}
