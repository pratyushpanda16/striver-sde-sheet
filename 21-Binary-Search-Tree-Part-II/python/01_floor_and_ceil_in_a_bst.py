from typing import List, Optional

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def floorCeilOfBST(self, root: Optional[TreeNode], key: int) -> List[int]:
        def find_floor(node: Optional[TreeNode], k: int) -> int:
            floor = -1
            while node:
                if node.val == k:
                    return node.val
                elif node.val < k:
                    floor = node.val
                    node = node.right
                else:
                    node = node.left
            return floor

        def find_ceil(node: Optional[TreeNode], k: int) -> int:
            ceil = -1
            while node:
                if node.val == k:
                    return node.val
                elif node.val > k:
                    ceil = node.val
                    node = node.left
                else:
                    node = node.right
            return ceil

        return [find_floor(root, key), find_ceil(root, key)]
