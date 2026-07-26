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
    public List<Integer> boundaryOfBinaryTree(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        if (root == null) return ans;
        ans.add(root.val);
        if (root.left == root.right) {
            return ans;
        }
        List<Integer> left = new ArrayList<>();
        List<Integer> leaves = new ArrayList<>();
        List<Integer> right = new ArrayList<>();
        dfs(left, root.left, 0);
        dfs(leaves, root, 1);
        dfs(right, root.right, 2);

        ans.addAll(left);
        ans.addAll(leaves);
        Collections.reverse(right);
        ans.addAll(right);
        return ans;
    }

    private void dfs(List<Integer> nums, TreeNode root, int i) {
        if (root == null) {
            return;
        }
        if (i == 0) {
            if (root.left != root.right) {
                nums.add(root.val);
                if (root.left != null) {
                    dfs(nums, root.left, i);
                } else {
                    dfs(nums, root.right, i);
                }
            }
        } else if (i == 1) {
            if (root.left == root.right) {
                nums.add(root.val);
            } else {
                dfs(nums, root.left, i);
                dfs(nums, root.right, i);
            }
        } else {
            if (root.left != root.right) {
                nums.add(root.val);
                if (root.right != null) {
                    dfs(nums, root.right, i);
                } else {
                    dfs(nums, root.left, i);
                }
            }
        }
    }
}
