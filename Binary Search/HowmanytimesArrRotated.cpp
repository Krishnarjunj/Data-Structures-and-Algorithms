//Krishhhhh
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	vector<int> a(n);

	for(int i = 0 ; i < n ; i ++){
		cin>>a[i];
	}
	int index = -1;
	int st = 0;
	int en = n - 1;
	int ans = INT_MAX;

	while(st <= en){
		int mid = (st + en)/2;
		if(a[mid] >= a[st]){
			if(ans > a[st]){
				ans = a[st];
				index = st;
			}
			st = mid + 1;
		}
		else{
			if(ans > a[mid]){
				ans = a[mid];
				index = mid;
			}
			en = mid - 1;
		}
	}
	cout<<index;

}
