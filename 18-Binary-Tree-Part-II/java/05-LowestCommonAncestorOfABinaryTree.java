import java.util.*;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        Map<TreeNode, TreeNode> parent = new HashMap<>();
        Queue<TreeNode> queue = new LinkedList<>();
        parent.put(root, null);
        queue.add(root);

        while (!parent.containsKey(p) || !parent.containsKey(q)) {
            TreeNode node = queue.poll();
            if (node.left != null) {
                parent.put(node.left, node);
                queue.add(node.left);
            }
            if (node.right != null) {
                parent.put(node.right, node);
                queue.add(node.right);
            }
        }

        Set<TreeNode> ancestors = new HashSet<>();
        TreeNode current = p;
        while (current != null) {
            ancestors.add(current);
            current = parent.get(current);
        }

        current = q;
        while (!ancestors.contains(current)) {
            current = parent.get(current);
        }

        return current;
    }
}
