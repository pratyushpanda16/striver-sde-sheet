class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        max_width = 0
        leftmost_indices = []

        def dfs(node, depth, index):
            nonlocal max_width
            if not node:
                return

            if depth == len(leftmost_indices):
                leftmost_indices.append(index)

            width = index - leftmost_indices[depth] + 1
            max_width = max(max_width, width)

            normalized_index = index - leftmost_indices[depth]
            dfs(node.left, depth + 1, 2 * normalized_index)
            dfs(node.right, depth + 1, 2 * normalized_index + 1)

        dfs(root, 0, 0)
        return max_width
