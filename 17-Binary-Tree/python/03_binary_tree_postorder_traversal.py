class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        stack = []
        current = root
        previous = None

        while current or stack:
            while current:
                stack.append(current)
                current = current.left

            current = stack[-1]

            if not current.right or current.right == previous:
                result.append(current.val)
                previous = current
                stack.pop()
                current = None
            else:
                current = current.right

        return result
