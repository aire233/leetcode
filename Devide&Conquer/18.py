# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        return self.buildTreeHelper(preorder, inorder, 0, 0, len(inorder) - 1)
    
    def buildTreeHelper(self, preorder, inorder, preStart, inStart, inEnd):
        if preStart >= len(preorder) or inStart > inEnd:
            return None
        root = TreeNode(preorder[preStart])
        inIndex = inStart
        while inIndex <= inEnd:
            if inorder[inIndex] == root.val:
                break
            inIndex += 1
        root.left = self.buildTreeHelper(preorder, inorder, preStart + 1, inStart, inIndex - 1)
        root.right = self.buildTreeHelper(preorder, inorder, preStart + inIndex - inStart + 1, inIndex + 1, inEnd)
        return root