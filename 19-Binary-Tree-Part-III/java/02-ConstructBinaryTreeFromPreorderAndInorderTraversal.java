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
    private int preIndex = 0;
    private int inIndex = 0;

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return build(preorder, inorder, Integer.MIN_VALUE);
    }

    private TreeNode build(int[] preorder, int[] inorder, int stop) {
        if (preIndex == preorder.length || inorder[inIndex] == stop) {
            return null;
        }

        TreeNode root = new TreeNode(preorder[preIndex++]);
        root.left = build(preorder, inorder, root.val);
        inIndex++;
        root.right = build(preorder, inorder, stop);

        return root;
    }
}
