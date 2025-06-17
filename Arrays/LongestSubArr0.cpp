//Krishhhhh
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int brutesolve(vector<int> arr){
	int n = arr.size();
	int ans = INT_MIN;
	for(int i = 0 ; i < n ; i++){
		for(int j = i  ; j < n ; j ++){
			int sum = 0 ;
			for(int k = i; k <= j ; k++){
				sum += arr[k];
				if(sum == 0 ){
					ans = max(ans , j - i + 1);
				}
			}
		}
	}
	return ans;
}

int bettersol(vector<int> arr){
	int n = arr.size();
	int sum = 0 ;
	int ans = INT_MIN;
	unordered_map<int, int> hash;
	for(int i = 0 ; i < n ; i ++){
		sum += arr[i];

		if(sum==0){
			ans = i;
		}

		else{
			if(hash.find(sum) == hash.end()){
				hash[sum] = i;
			}
			else if(hash.find(sum) != hash.end()){
				ans = max(ans , i - hash[sum] );
			}
		}
	}
	return ans;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> arr = {1,2,-2,4,-4, 0};

	cout<< brutesolve(arr) << endl;
	cout<< bettersol(arr) << endl;
}
