from typing import List, Optional

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        result = []

        def dfs(node: Optional[TreeNode], level: int):
            if not node:
                return

            if level == len(result):
                result.append([])

            if level % 2 == 0:
                result[level].append(node.val)
            else:
                result[level].insert(0, node.val)

            dfs(node.left, level + 1)
            dfs(node.right, level + 1)

        dfs(root, 0)
        return result
