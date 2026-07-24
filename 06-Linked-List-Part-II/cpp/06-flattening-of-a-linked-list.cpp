class Solution {
private:
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode dummy(-1);
        ListNode* curr = &dummy;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                curr->child = list1;
                list1 = list1->child;
            } else {
                curr->child = list2;
                list2 = list2->child;
            }
            curr = curr->child;
            curr->next = nullptr;
        }

        if (list1) {
            curr->child = list1;
        } else {
            curr->child = list2;
        }

        return dummy.child;
    }

public:
    ListNode* flattenLinkedList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* flattenedRight = flattenLinkedList(head->next);
        return merge(head, flattenedRight);
    }
};
