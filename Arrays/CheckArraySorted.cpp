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
    bool ans1 = true;
    bool ans2 = true;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i>=1){
            if(a[i-1]>a[i]){
                ans1 = false;
            }
            if(a[i-1]<a[i]){
                ans2 = false;
            }
        }
    }

    if(ans1 == true || ans2 == true){
        cout<<"Sorted"<<endl;
    }
    else{
        cout<<"Not Sorted"<<endl;
    }


}
