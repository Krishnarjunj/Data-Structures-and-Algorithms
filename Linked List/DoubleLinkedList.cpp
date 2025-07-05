#include<bits/stdc++.h>
using namespace std;

struct Node{
  public:
  int data;
  Node* next;
  Node* back;

  public:
  Node(int data1, Node* next1, Node* back1){
    data = data1;
    next = next1;
    back = back1;
  }
  Node(int data2, Node* next2){
    data = data2;
    next = next2;
    back = NULL;
  }
};
