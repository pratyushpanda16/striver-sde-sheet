from typing import Optional

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        if not root:
            return False

        left_stack = []
        right_stack = []

        def push_all_left(node: Optional[TreeNode]):
            while node:
                left_stack.append(node)
                node = node.left

        def push_all_right(node: Optional[TreeNode]):
            while node:
                right_stack.append(node)
                node = node.right

        push_all_left(root)
        push_all_right(root)

        left_node = left_stack.pop()
        right_node = right_stack.pop()

        while left_node != right_node:
            s = left_node.val + right_node.val
            if s == k:
                return True

            if s < k:
                push_all_left(left_node.right)
                left_node = left_stack.pop()
            else:
                push_all_right(right_node.left)
                right_node = right_stack.pop()

        return False
