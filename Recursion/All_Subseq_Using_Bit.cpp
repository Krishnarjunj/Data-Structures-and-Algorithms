//Krishhhhh
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	cin>>str;
	vector<string> ans;
	int n = str.size();

	for(int i = 0 ; i < (1 << n) ; i++ ){
		string sub = "";
		for(int j = 0 ; j < n ; j ++){
			if(i & (1 << j)){
				sub += str[j];
			}
		}
		if(!sub.empty()) ans.push_back(sub);
	}

	for(auto it : ans){
		cout<<it<<" ";
	}

}
