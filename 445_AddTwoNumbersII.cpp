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
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Use vector to store big integers.
        vector<int> num1, num2;
        ListNode *temp1 = l1, *temp2 = l2;
        while (temp1) {
            num1.push_back(temp1->val);
            temp1 = temp1->next;
        }
        
        while (temp2) {
            num2.push_back(temp2->val);
            temp2 = temp2->next;
        }
        
        ListNode *head = nullptr;
        int carry = 0, i, j;
        for (i = num1.size()-1, j = num2.size()-1; i >= 0 && j >= 0; --i, --j ) {
            int sum = num1[i] + num2[j] + carry;
            int val = sum % 10;
            carry = sum / 10;
            ListNode *temp = new ListNode(val);
            temp->next = head;
            head = temp;
        }

        while (i >= 0) {
            int sum = num1[i] + carry;
            carry = sum / 10;
            ListNode *temp = new ListNode(sum % 10);
            temp->next = head;
            head = temp;
            --i;
        }

        while (j >= 0) {
            int sum = num2[j] + carry;
            carry = sum / 10;
            ListNode *temp = new ListNode(sum % 10);
            temp->next = head;
            head = temp;
            --j;
        }
        
        if (carry > 0) {
            ListNode *temp = new ListNode(carry);
            temp->next = head;
            head = temp;
        }

        return head;
    }
    
    
    // Does not work for big integers.
    ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
        unsigned long long a = 0, b = 0;
        ListNode *temp1 = l1, *temp2 = l2;
        
        while (temp1) {
            a = a*10 + temp1->val;
            temp1 = temp1->next;
        }
        
        while (temp2) {
            b = b*10 + temp2->val;
            temp2 = temp2->next;
        }
        
        unsigned long long c = a + b;
        ListNode *head = nullptr;
        if (c == 0) {
            head = new ListNode(0);
        } else {
            while (c > 0) {
                int digit = c % 10;
                ListNode* temp = new ListNode(digit);
                temp->next = head;
                head = temp;
                c = c/10;
            }
        }
        
        return head;
    }
};
