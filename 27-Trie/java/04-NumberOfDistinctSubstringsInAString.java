class Solution {
    static class Node {
        Node[] children = new Node[26];
    }

    public int countDistinctSubstring(String s) {
        Node root = new Node();
        int count = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            Node curr = root;
            for (int j = i; j < n; j++) {
                int idx = s.charAt(j) - 'a';
                if (curr.children[idx] == null) {
                    curr.children[idx] = new Node();
                    count++;
                }
                curr = curr.children[idx];
            }
        }

        return count + 1; // +1 for empty substring
    }
}
