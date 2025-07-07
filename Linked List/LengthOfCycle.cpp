/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    int countNodesinLoop(Node *head) {
        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Loop found, count its length
                int count = 1;
                Node* temp = slow->next;
                while (temp != slow) {
                    count++;
                    temp = temp->next;
                }
                return count;
            }
        }

        return 0;
    }
};
