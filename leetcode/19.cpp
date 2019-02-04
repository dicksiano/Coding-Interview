class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head,  *q = head;
        for(;  q && n > -1; n--) q = q->next;
        if(!q && n > -1) return head->next; // Query for elimination o the head
        
        for(; q; q = q->next, p = p->next);
        
        q = p->next;
        p->next = p->next->next;
        return head;
    }
}
