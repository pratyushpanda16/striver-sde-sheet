from typing import List, Optional

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def boundaryOfBinaryTree(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        
        ans = [root.val]
        if root.left == root.right:
            return ans

        left, leaves, right = [], [], []

        def dfs(nums: List[int], node: Optional[TreeNode], flag: int):
            if not node:
                return

            if flag == 0:
                if node.left or node.right:
                    nums.append(node.val)
                    if node.left:
                        dfs(nums, node.left, flag)
                    else:
                        dfs(nums, node.right, flag)
            elif flag == 1:
                if not node.left and not node.right:
                    nums.append(node.val)
                else:
                    dfs(nums, node.left, flag)
                    dfs(nums, node.right, flag)
            else:
                if node.left or node.right:
                    nums.append(node.val)
                    if node.right:
                        dfs(nums, node.right, flag)
                    else:
                        dfs(nums, node.left, flag)

        dfs(left, root.left, 0)
        dfs(leaves, root, 1)
        dfs(right, root.right, 2)

        return ans + left + leaves + right[::-1]
