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
    void reorderList(ListNode* head) {
        ListNode *p, *q;
        stack<ListNode*> s;
        for(p = head; p; p = p->next) s.push(p);
        
        p = head;
        while(p && p->next) {
            q = s.top(); s.pop();
            s.top()->next = nullptr;
            
            q->next = p->next;
            p->next = q;
            p = p->next->next;
        }
    }
};
