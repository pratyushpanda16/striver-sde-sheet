from typing import Optional

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.max_diameter = 0

        def dfs(node: Optional[TreeNode]) -> int:
            if not node:
                return 0
            
            left_height = dfs(node.left)
            right_height = dfs(node.right)

            self.max_diameter = max(self.max_diameter, left_height + right_height)

            return 1 + max(left_height, right_height)

        dfs(root)
        return self.max_diameter
