from typing import Optional

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxSumBST(self, root: Optional[TreeNode]) -> int:
        self.ans = 0
        inf = 1 << 30

        def dfs(node: Optional[TreeNode]):
            if not node:
                return (1, inf, -inf, 0)

            l_is_bst, l_min, l_max, l_sum = dfs(node.left)
            r_is_bst, r_min, r_max, r_sum = dfs(node.right)
            v = node.val

            if l_is_bst and r_is_bst and l_max < v < r_min:
                s = v + l_sum + r_sum
                self.ans = max(self.ans, s)
                return (1, min(l_min, v), max(r_max, v), s)

            return (0, 0, 0, 0)

        dfs(root)
        return self.ans
