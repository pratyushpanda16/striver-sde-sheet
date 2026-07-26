from typing import List, Optional

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def kLargesSmall(self, root: Optional[TreeNode], k: int) -> List[int]:
        inorder = []

        def inorder_traversal(node: Optional[TreeNode]):
            if not node:
                return
            inorder_traversal(node.left)
            inorder.append(node.val)
            inorder_traversal(node.right)

        inorder_traversal(root)

        return [inorder[k - 1], inorder[len(inorder) - k]]
