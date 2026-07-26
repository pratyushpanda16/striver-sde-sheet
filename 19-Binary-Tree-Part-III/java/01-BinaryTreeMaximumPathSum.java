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
    public int maxPathSum(TreeNode root) {
        Deque<TreeNode> stack = new ArrayDeque<>();
        List<TreeNode> order = new ArrayList<>();
        stack.push(root);
        while (!stack.isEmpty()) {
            TreeNode node = stack.pop();
            order.add(node);
            if (node.left != null) stack.push(node.left);
            if (node.right != null) stack.push(node.right);
        }

        Map<TreeNode, Integer> gain = new HashMap<>();
        int maxSum = Integer.MIN_VALUE;
        for (int i = order.size() - 1; i >= 0; i--) {
            TreeNode node = order.get(i);
            int leftGain = Math.max(gain.getOrDefault(node.left, 0), 0);
            int rightGain = Math.max(gain.getOrDefault(node.right, 0), 0);
            maxSum = Math.max(maxSum, node.val + leftGain + rightGain);
            gain.put(node, node.val + Math.max(leftGain, rightGain));
        }
        return maxSum;
    }
}
