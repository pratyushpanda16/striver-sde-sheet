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
    public boolean checkChildrenSum(TreeNode root) {
        if (root == null || (root.left == null && root.right == null)) return true;
        int leftVal = root.left != null ? root.left.val : 0;
        int rightVal = root.right != null ? root.right.val : 0;
        if (root.val != leftVal + rightVal) return false;
        return checkChildrenSum(root.left) && checkChildrenSum(root.right);
    }
}
