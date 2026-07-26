from typing import Optional

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True

        heights = {}
        stack = [root]

        while stack:
            node = stack.pop()

            left_done = node.left is None or node.left in heights
            right_done = node.right is None or node.right in heights

            if not left_done or not right_done:
                stack.append(node)
                if not left_done:
                    stack.append(node.left)
                if not right_done:
                    stack.append(node.right)
                continue

            left_height = 0 if node.left is None else heights[node.left]
            right_height = 0 if node.right is None else heights[node.right]

            if abs(left_height - right_height) > 1:
                return False

            heights[node] = 1 + max(left_height, right_height)

        return True
