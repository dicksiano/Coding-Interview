/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
    Time: O(n klogk)
    Space: O(nk)
*/

class Solution {
public:
    priority_queue<int> buildHeap(vector<ListNode*>& l) {
        priority_queue<int> pq;
        for(int i = 0; i < l.size(); i++) {
            ListNode* q, *head = l[i];
            for(ListNode* p = head; p != nullptr && p->next != nullptr; ) {
                pq.push(p->next->val);
                q = p->next;
                p->next = p->next->next;
                free(q);
            }
            if(head != nullptr) {
                pq.push(head->val);
                free(head);
            }
        }
        return pq;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int> heap = buildHeap(lists);
        
        ListNode* head = nullptr, *p;
        while(!heap.empty()) {
            if(head == nullptr) head = p = new ListNode(heap.top());
            else p = new ListNode(heap.top()), p->next = head, head = p;
            heap.pop();
        }
        return head;                             
    }
};
