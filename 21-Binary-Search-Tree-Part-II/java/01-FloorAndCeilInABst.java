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
    public List<Integer> floorCeilOfBST(TreeNode root, int key) {
        int floor = findFloor(root, key);
        int ceil = findCeil(root, key);
        List<Integer> result = new ArrayList<>();
        result.add(floor);
        result.add(ceil);
        return result;
    }

    private int findFloor(TreeNode root, int key) {
        int floor = -1;
        while (root != null) {
            if (root.val == key) {
                return root.val;
            } else if (root.val < key) {
                floor = root.val;
                root = root.right;
            } else {
                root = root.left;
            }
        }
        return floor;
    }

    private int findCeil(TreeNode root, int key) {
        int ceil = -1;
        while (root != null) {
            if (root.val == key) {
                return root.val;
            } else if (root.val > key) {
                ceil = root.val;
                root = root.left;
            } else {
                root = root.right;
            }
        }
        return ceil;
    }
}
