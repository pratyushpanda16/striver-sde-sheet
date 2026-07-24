class Solution {
    private ListNode merge(ListNode list1, ListNode list2) {
        ListNode dummy = new ListNode(-1);
        ListNode curr = dummy;

        while (list1 != null && list2 != null) {
            if (list1.val <= list2.val) {
                curr.child = list1;
                list1 = list1.child;
            } else {
                curr.child = list2;
                list2 = list2.child;
            }

            curr = curr.child;
            curr.next = null;
        }

        if (list1 != null) {
            curr.child = list1;
        } else {
            curr.child = list2;
        }

        return dummy.child;
    }

    public ListNode flattenLinkedList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode flattenedRight = flattenLinkedList(head.next);

        return merge(head, flattenedRight);
    }
}
