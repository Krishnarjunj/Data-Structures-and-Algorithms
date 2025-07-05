/* Link list node */
/*
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
}; */

class Solution {
  public:
    // Function to count nodes of a linked list.
    int getCount(struct Node* head) {

        // Code here
        Node* temp = head;
        if(temp==NULL) return 0;
        int c = 1 ;
        while(temp->next!=NULL){
            c++;
            temp = temp->next;
        }
        return c;
    }
};
