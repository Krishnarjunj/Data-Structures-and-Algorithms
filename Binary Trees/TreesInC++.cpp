//Krishhhhh
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Node{
	int data;
	struct Node* right;
	struct Node* left;

	Node(int val){
		data = val;
		left = right = NULL;
	}
};


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	struct Node* root = new Node(1);
	root -> left = new Node(2);
	root -> right = new Node(3);
	root -> left -> right = new Node(4);

}
