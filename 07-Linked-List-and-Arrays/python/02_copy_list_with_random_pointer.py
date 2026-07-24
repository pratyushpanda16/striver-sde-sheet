class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return None

        curr = head
        while curr:
            copy = Node(curr.val, curr.next)
            curr.next = copy
            curr = copy.next

        curr = head
        while curr:
            if curr.random:
                curr.next.random = curr.random.next
            curr = curr.next.next

        copy_head = head.next
        curr = head
        copy_curr = copy_head
        while curr:
            curr.next = copy_curr.next
            curr = curr.next
            if curr:
                copy_curr.next = curr.next
                copy_curr = copy_curr.next
            else:
                copy_curr.next = None

        return copy_head
