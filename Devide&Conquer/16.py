# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.maxSum = float('-inf')
        self.maxPath(root)
        return self.maxSum
    
    def maxPath(self, root):
        if root is None:
            return 0
        left = max(0, self.maxPath(root.left))
        right = max(0, self.maxPath(root.right))
        self.maxSum = max(self.maxSum, left + right + root.val)
        # not return left + right + root.val, because it is not a path
        return max(left, right) + root.val