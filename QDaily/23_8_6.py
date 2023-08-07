# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        node0 = dummy = ListNode(next=head)  # 用哨兵节点简化代码逻辑
        node1 = head
        while node1 and node1.next:
            node3 = node1.next.next # node3
            node0.next = node1.next # 0 -> 2
            node0.next.next = node1 # 2 -> 1
            node1.next = node3 # 1 -> 3

            node0 = node1 
            node1 = node3 
        return dummy.next 