class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        Deque<TreeNode> stack = new ArrayDeque<>();
        TreeNode current = root;
        TreeNode previous = null;

        while (current != null || !stack.isEmpty()) {
            while (current != null) {
                stack.push(current);
                current = current.left;
            }

            current = stack.peek();

            if (current.right == null || current.right == previous) {
                result.add(current.val);
                previous = current;
                stack.pop();
                current = null;
            } else {
                current = current.right;
            }
        }

        return result;
    }
}
