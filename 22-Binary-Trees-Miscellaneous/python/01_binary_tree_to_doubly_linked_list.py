from typing import Optional

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def bToDLL(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        self.prev = None
        self.head = None

        def inorder(node: Optional[TreeNode]):
            if not node:
                return

            inorder(node.left)

            if not self.prev:
                self.head = node
            else:
                self.prev.right = node
                node.left = self.prev
            self.prev = node

            inorder(node.right)

        inorder(root)
        return self.head
