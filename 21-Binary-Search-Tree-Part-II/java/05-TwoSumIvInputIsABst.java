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
    public boolean findTarget(TreeNode root, int k) {
        Deque<TreeNode> leftStack = new ArrayDeque<>();
        Deque<TreeNode> rightStack = new ArrayDeque<>();

        pushAllLeft(root, leftStack);
        pushAllRight(root, rightStack);

        TreeNode leftNode = leftStack.pop();
        TreeNode rightNode = rightStack.pop();

        while (leftNode != rightNode) {
            int sum = leftNode.val + rightNode.val;
            if (sum == k) return true;

            if (sum < k) {
                pushAllLeft(leftNode.right, leftStack);
                leftNode = leftStack.pop();
            } else {
                pushAllRight(rightNode.left, rightStack);
                rightNode = rightStack.pop();
            }
        }
        return false;
    }

    private void pushAllLeft(TreeNode node, Deque<TreeNode> stack) {
        while (node != null) {
            stack.push(node);
            node = node.left;
        }
    }

    private void pushAllRight(TreeNode node, Deque<TreeNode> stack) {
        while (node != null) {
            stack.push(node);
            node = node.right;
        }
    }
}
