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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;
        
        ListNode *odd_head = head, *even_head = head->next;
        ListNode *curr_odd = odd_head, *curr_even = even_head;
        while (curr_odd && curr_even) {
            if (curr_odd->next)
                curr_odd->next = curr_odd->next->next;
            if (curr_odd->next)
                curr_odd = curr_odd->next;
            if (curr_even->next)
                curr_even->next = curr_even->next->next;
            curr_even = curr_even->next;
        }
        
        curr_odd->next = even_head;
        return odd_head;
    }
};
