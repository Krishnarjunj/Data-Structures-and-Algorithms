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
    bool searchKey(int n, Node* head, int key) {
        // Code here
        Node* temp = head;
        if(head->next==NULL && head->data==key) return true;
        if(head->next==NULL) return false;
        
        while(temp!=NULL){
            if(temp->data == key){
                return true;
            }
            temp=temp->next;
        }
        return false;
    }
};
