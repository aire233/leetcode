#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{ // priority_queue
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        auto cmp = [](ListNode *a, ListNode *b)
        { return a->val > b->val; };
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq(cmp);
        for (auto list : lists)
        {
            if (list)
                pq.push(list);
        }
        ListNode *head = new ListNode(0);
        ListNode *cur = head;
        while (!pq.empty())
        {
            ListNode *node = pq.top();
            pq.pop();
            cur->next = node;
            cur = cur->next;
            if (node->next)
                pq.push(node->next);
        }
        return head->next;
    }
};


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
class Solution 
{ // divide and conquer
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKLists(lists, 0, lists.size());
    }
private:
    ListNode* mergeKLists(vector<ListNode*>& lists, int l, int r)
    {
        int d = r - l;
        if(!d) return nullptr;
        if(d == 1) return lists[l];
        ListNode* left = mergeKLists(lists, l, l + d / 2);
        ListNode* right = mergeKLists(lists, l + d/ 2, r);
        return mergeLists(left, right);
    }

    ListNode* mergeLists(ListNode* list1, ListNode* list2)
    {
        ListNode *dummy = new ListNode(0), *cur = dummy;
        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
                cur->next = list1;
                list1 = list1->next;
            }
            else
            {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        cur->next = list1 ? list1 : list2;
        return dummy->next;
    }
};