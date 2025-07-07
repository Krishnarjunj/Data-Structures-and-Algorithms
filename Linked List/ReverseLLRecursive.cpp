/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    void reverse(ListNode* &prev, ListNode* &curr, ListNode* &nxt ){
        curr->next = prev;
        prev = curr;
        curr = nxt;
        nxt = nxt->next;
        if(nxt==NULL){
            curr->next = prev;
            return;
        }
        reverse(prev, curr, nxt);
    }

    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return head;
        if(head->next==NULL) return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nxt = head->next;
        reverse(prev, curr, nxt);
        return curr;
    }
};
