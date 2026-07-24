class Solution:
    def merge(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(-1)
        curr = dummy

        while list1 and list2:
            if list1.val <= list2.val:
                curr.child = list1
                list1 = list1.child
            else:
                curr.child = list2
                list2 = list2.child

            curr = curr.child
            curr.next = None

        if list1:
            curr.child = list1
        else:
            curr.child = list2

        return dummy.child

    def flattenLinkedList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head

        flattened_right = self.flattenLinkedList(head.next)
        return self.merge(head, flattened_right)
