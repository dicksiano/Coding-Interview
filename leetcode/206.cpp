class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev, *curr, *next;
        prev = next = nullptr;
        curr = head;
        
        while(curr) {
            next = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
