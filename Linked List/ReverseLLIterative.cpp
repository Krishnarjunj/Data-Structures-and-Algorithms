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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr) return head;
        if(head->next==nullptr) return head;
        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* nxt = head->next;
        while(nxt->next!=NULL){
            cur->next = pre;
            pre = cur;
            cur = nxt;
            nxt = nxt->next;
        }
        cur->next = pre;
        return cur;
    }
};
