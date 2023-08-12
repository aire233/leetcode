class Solution:
    def reverseBetween(self, head: ListNode, left: int, right: int) -> ListNode:
        def reverse_linked_list(head: ListNode):
            pre = None
            cur = head
            while cur:
                next = cur.next
                cur.next = pre
                pre = cur
                cur = next

        pre = dummy = ListNode(next=head)
        for _ in range(left - 1):
            pre = pre.next
        right_node = pre
        for _ in range(right - left + 1):
            right_node = right_node.next
        
        
        left_node = pre.next
        curr = right_node.next
        pre.next = None
        right_node.next = None

        
        reverse_linked_list(left_node)
 
        pre.next = right_node
        left_node.next = curr
        return dummy.next