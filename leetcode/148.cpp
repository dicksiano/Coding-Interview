/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *partition(ListNode *p, int n) {
        for(int i = 0; p && i < n-1; i++) p = p->next;
        
        if(!p) return nullptr;
        ListNode* q = p->next;
        p->next = nullptr;
        
        return q;
    }
    
    ListNode *merge(ListNode *a, ListNode *b, ListNode *p) {
        ListNode *q = p;
        while(a && b) {
            if(a->val > b->val) q->next = b, q = b, b = b->next;
            else q->next = a, q = a, a = a->next;
        }
        
        q->next = a ? a : b;
        while(q->next) q = q->next;
        
        return q;
    }
    
    ListNode* sortList(ListNode* head) {
        if(!head || !(head->next)) return head;
        
        ListNode *p = head, *q = new ListNode(0), *l, *r, *tail;
        q->next = p;
        int len = 0;
        
        while(p) len++, p = p->next;
        for(int step = 1; step < len; step *= 2) {
            p = q->next;
            tail = q;
            
            while(p) {
                l = p;
                r = partition(l, step);
                p = partition(r, step);
                tail = merge(l, r, tail);
            }
        }
        return q->next;
    }
};
