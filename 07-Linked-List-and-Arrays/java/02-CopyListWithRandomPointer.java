class Solution {
    public Node copyRandomList(Node head) {
        if (head == null) return null;

        Node current = head;
        while (current != null) {
            Node copy = new Node(current.val);
            copy.next = current.next;
            current.next = copy;
            current = copy.next;
        }

        current = head;
        while (current != null) {
            if (current.random != null) {
                current.next.random = current.random.next;
            }
            current = current.next.next;
        }

        Node copyHead = head.next;
        current = head;
        Node copyCurrent = copyHead;
        while (current != null) {
            current.next = copyCurrent.next;
            current = current.next;
            if (current != null) {
                copyCurrent.next = current.next;
                copyCurrent = copyCurrent.next;
            } else {
                copyCurrent.next = null;
            }
        }

        return copyHead;
    }
}
