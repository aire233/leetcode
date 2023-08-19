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
    int carry;
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        int carry = 0, cnt;
        while(l1 || l2 || carry)
        {
            cnt = carry;
            if(l1) cnt += l1->val;
            if(l2) cnt += l2->val;
            ListNode* tmp = new ListNode(cnt % 10);
            carry = cnt / 10;
            cur->next = tmp;
            cur = tmp;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return dummy->next;
    }
};