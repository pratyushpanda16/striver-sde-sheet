class Solution:
    def treeTraversal(self, root):
        inorder = []
        preorder = []
        postorder = []

        def traverse(node):
            if not node:
                return
            preorder.append(node.data)
            traverse(node.left)
            inorder.append(node.data)
            traverse(node.right)
            postorder.append(node.data)

        traverse(root)
        return [inorder, preorder, postorder]
