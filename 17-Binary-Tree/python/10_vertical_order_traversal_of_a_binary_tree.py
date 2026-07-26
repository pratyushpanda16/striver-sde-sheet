class Solution:
    def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        nodes = []

        def dfs(node, row, col):
            if not node:
                return
            nodes.append((col, row, node.val))
            dfs(node.left, row + 1, col - 1)
            dfs(node.right, row + 1, col + 1)

        dfs(root, 0, 0)
        nodes.sort()

        ans = []
        prev = float('-inf')
        for col, row, val in nodes:
            if col != prev:
                ans.append([])
                prev = col
            ans[-1].append(val)

        return ans
