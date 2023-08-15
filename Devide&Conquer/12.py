# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        def setBST(left, right):
            if left > right:
                return None
            mid = (left + right) >> 1
            root = TreeNode(nums[mid])
            root.left = setBST(left, mid - 1)
            root.right = setBST(mid + 1, right)
            return root
        return setBST(0, len(nums) - 1)