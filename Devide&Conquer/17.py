# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    ans = []
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        self.ans = []
        self.rightSideViewHelper(root, 0)
        return self.ans
    
    def rightSideViewHelper(self, root, level):
        if root is None:
            return
        if level == len(self.ans):
            self.ans.append(root.val)
        self.rightSideViewHelper(root.right, level + 1)
        self.rightSideViewHelper(root.left, level + 1)