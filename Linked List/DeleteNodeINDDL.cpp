/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    // Function to delete a node at given position.
    Node* deleteNode(Node* head, int x) {
        // Your code here
        //HEAD
        if(head==NULL || head->next==NULL) return NULL;
        
        if(x==1){
            Node* temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
            return head;
        }
        
        Node* temp = head;
        
        for(int i = 2 ; i < x ; i++){
            temp = temp->next;    
        }
        //LAST
        if(temp->next->next == NULL){
            Node* last = temp->next;
            temp->next = NULL;
            delete last;
        }
        //MIDDLE
        else{
            Node* midafter = temp->next->next;
            temp->next = midafter;
            midafter->prev = temp;
        }
        return head;
        
        
    }
};
