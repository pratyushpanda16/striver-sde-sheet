class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        Node* current = head;
        while (current) {
            Node* copy = new Node(current->val);
            copy->next = current->next;
            current->next = copy;
            current = copy->next;
        }

        current = head;
        while (current) {
            if (current->random) {
                current->next->random = current->random->next;
            }
            current = current->next->next;
        }

        Node* copyHead = head->next;
        current = head;
        Node* copyCurrent = copyHead;
        while (current) {
            current->next = copyCurrent->next;
            current = current->next;
            if (current) {
                copyCurrent->next = current->next;
                copyCurrent = copyCurrent->next;
            } else {
                copyCurrent->next = nullptr;
            }
        }

        return copyHead;
    }
};
