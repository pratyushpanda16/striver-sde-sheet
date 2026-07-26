class Solution {
    List<List<Integer>> treeTraversal(TreeNode root) {
        List<Integer> inorder = new ArrayList<>();
        List<Integer> preorder = new ArrayList<>();
        List<Integer> postorder = new ArrayList<>();

        traverse(root, inorder, preorder, postorder);

        List<List<Integer>> result = new ArrayList<>();
        result.add(inorder);
        result.add(preorder);
        result.add(postorder);
        return result;
    }

    private void traverse(TreeNode node, List<Integer> inorder,
                           List<Integer> preorder, List<Integer> postorder) {
        if (node == null) return;

        preorder.add(node.data);
        traverse(node.left, inorder, preorder, postorder);
        inorder.add(node.data);
        traverse(node.right, inorder, preorder, postorder);
        postorder.add(node.data);
    }
}
