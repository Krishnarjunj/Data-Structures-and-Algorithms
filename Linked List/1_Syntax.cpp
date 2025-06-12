//Krishhhhh
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Node{
public:
	int data;
	Node* next;
public:
	Node(int data1, Node* next1){
		data = data1;
		next = next1;
	}

	Node(int data1){
		data = data1;
		next = NULL;
	}
};


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> arr = {1,2,3,4,5};
	Node* y = new Node(arr[2]);
	cout<<y->data;

	

}
