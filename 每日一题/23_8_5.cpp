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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode *p = dummy;
        while(list1 && list2){
            ListNode* tmp = new ListNode;
            if(list1->val < list2->val)
            {
                 tmp->val = list1->val;
                 list1 = list1->next;
            }
            else
            {
                tmp->val = list2->val;
                list2 = list2->next;
            }
            
            p->next = tmp;
            p = p->next;
        }
        if(list1)
            p->next = list1;
        if(list2)
            p->next = list2;
        return dummy->next;
    }
};