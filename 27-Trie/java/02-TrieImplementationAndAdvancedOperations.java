class Trie {
    static class Node {
        Node[] children = new Node[26];
        int endCount = 0;
        int prefixCount = 0;
    }

    private Node root;

    public Trie() {
        root = new Node();
    }

    public void insert(String word) {
        Node curr = root;
        for (char c : word.toCharArray()) {
            int idx = c - 'a';
            if (curr.children[idx] == null) curr.children[idx] = new Node();
            curr = curr.children[idx];
            curr.prefixCount++;
        }
        curr.endCount++;
    }

    public int countWordsEqualTo(String word) {
        Node curr = root;
        for (char c : word.toCharArray()) {
            int idx = c - 'a';
            if (curr.children[idx] == null) return 0;
            curr = curr.children[idx];
        }
        return curr.endCount;
    }

    public int countWordsStartingWith(String prefix) {
        Node curr = root;
        for (char c : prefix.toCharArray()) {
            int idx = c - 'a';
            if (curr.children[idx] == null) return 0;
            curr = curr.children[idx];
        }
        return curr.prefixCount;
    }

    public void erase(String word) {
        if (countWordsEqualTo(word) == 0) return;
        Node curr = root;
        for (char c : word.toCharArray()) {
            int idx = c - 'a';
            curr = curr.children[idx];
            curr.prefixCount--;
        }
        curr.endCount--;
    }
}
