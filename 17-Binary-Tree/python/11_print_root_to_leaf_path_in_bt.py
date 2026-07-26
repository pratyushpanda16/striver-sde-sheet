class Solution:
    def allRootToLeaf(self, root):
        result = []

        def dfs(node, path):
            if not node:
                return

            path.append(node.data)

            if not node.left and not node.right:
                result.append(list(path))
            else:
                dfs(node.left, path)
                dfs(node.right, path)

            path.pop()

        dfs(root, [])
        return result
