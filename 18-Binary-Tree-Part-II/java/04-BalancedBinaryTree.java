import java.util.*;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isBalanced(TreeNode root) {
        if (root == null) {
            return true;
        }

        Map<TreeNode, Integer> heights = new HashMap<>();
        Deque<TreeNode> stack = new ArrayDeque<>();
        stack.push(root);

        while (!stack.isEmpty()) {
            TreeNode node = stack.pop();

            boolean leftDone = node.left == null || heights.containsKey(node.left);
            boolean rightDone = node.right == null || heights.containsKey(node.right);

            if (!leftDone || !rightDone) {
                stack.push(node);
                if (!leftDone) {
                    stack.push(node.left);
                }
                if (!rightDone) {
                    stack.push(node.right);
                }
                continue;
            }

            int leftHeight = node.left == null ? 0 : heights.get(node.left);
            int rightHeight = node.right == null ? 0 : heights.get(node.right);

            if (Math.abs(leftHeight - rightHeight) > 1) {
                return false;
            }

            heights.put(node, 1 + Math.max(leftHeight, rightHeight));
        }

        return true;
    }
}
