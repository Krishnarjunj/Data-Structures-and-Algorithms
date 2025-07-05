/*
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        // Your code here
        DLLNode* curr = head;
        DLLNode* newHead = nullptr;
        while(curr!=NULL){
            DLLNode* temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            newHead = curr;
            curr = curr->prev;
        }
        
        return newHead;
    }
};
