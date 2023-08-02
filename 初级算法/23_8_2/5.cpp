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
    bool isPalindrome(ListNode* head) {
        vector<int> stack;
        while(head!=nullptr)
        {
            stack.push_back(head->val);
            head = head->next;
        }
        int i = 0, j = stack.size() - 1;
        for(;i<j;)
        {
            if(stack[i]!=stack[j])
                return false;
            i++, j--;
        }
        return true;
    }
};