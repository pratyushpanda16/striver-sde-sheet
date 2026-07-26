from typing import List, Optional

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        self.post_idx = len(postorder) - 1
        self.in_idx = len(inorder) - 1

        def build(stop: float) -> Optional[TreeNode]:
            if self.post_idx < 0 or inorder[self.in_idx] == stop:
                return None

            root_val = postorder[self.post_idx]
            self.post_idx -= 1
            root = TreeNode(root_val)

            root.right = build(root_val)
            self.in_idx -= 1
            root.left = build(stop)

            return root

        return build(float('inf'))
