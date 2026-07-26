from typing import List, Optional

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        self.pre_idx = 0
        self.in_idx = 0

        def build(stop: float) -> Optional[TreeNode]:
            if self.pre_idx == len(preorder) or inorder[self.in_idx] == stop:
                return None

            root_val = preorder[self.pre_idx]
            self.pre_idx += 1
            root = TreeNode(root_val)

            root.left = build(root_val)
            self.in_idx += 1
            root.right = build(stop)

            return root

        return build(float('-inf'))
