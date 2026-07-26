from typing import Optional

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        stack = [root]
        order = []
        while stack:
            node = stack.pop()
            order.append(node)
            if node.left:
                stack.append(node.left)
            if node.right:
                stack.append(node.right)

        gain = {}
        max_sum = float('-inf')
        for node in reversed(order):
            left_gain = max(gain.get(node.left, 0), 0)
            right_gain = max(gain.get(node.right, 0), 0)
            max_sum = max(max_sum, node.val + left_gain + right_gain)
            gain[node] = node.val + max(left_gain, right_gain)

        return max_sum
