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
    private int postIndex;
    private int inIndex;

    public TreeNode buildTree(int[] inorder, int[] postorder) {
        postIndex = postorder.length - 1;
        inIndex = inorder.length - 1;
        return build(inorder, postorder, Integer.MAX_VALUE);  
    }

    private TreeNode build(int[] inorder, int[] postorder, int stop) {
        if (postIndex < 0 || inorder[inIndex] == stop) {
            return null;
        }

        TreeNode root = new TreeNode(postorder[postIndex--]);
        root.right = build(inorder, postorder, root.val);
        inIndex--;
        root.left = build(inorder, postorder, stop);
        return root;
    }
}
