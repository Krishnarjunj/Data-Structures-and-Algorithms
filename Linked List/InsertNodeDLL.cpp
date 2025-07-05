/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

// Function to insert a new node at given position in doubly linked list.
class Solution {
  public:
    // Function to insert a new node at given position in doubly linked list.
    Node *addNode(Node *head, int pos, int data) {
        // code here
        int c = pos;
        Node* temp = head;
        while(pos--){
            temp = temp->next;
        }
        Node* newNode = new Node(data);
        
        // LAST
        if(temp->next==NULL){
            temp->next = newNode;
            newNode->prev = temp;
        }
        // MIDDLE
        else{
            Node* temp2 = temp->next;
            newNode->next = temp2;
            newNode->prev = temp;
            temp2->prev = newNode;
            temp->next = newNode;
        }
        return head;
    }
};
