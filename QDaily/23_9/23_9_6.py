# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def lcaDeepestLeaves(self, root: TreeNode) -> TreeNode:
        def lca(root):
            if root is None:
                return 0, None
            
            d1, lca1 = lca(root.left)
            d2, lca2 = lca(root.right)

            if d1 > d2:
                return d1 + 1, lca1
            elif d1 < d2:
                return d2 + 1, lca2
            else:
                return d1 + 1, root
        
        return lca(root)[1]