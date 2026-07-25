class LFUCache {
    struct Node {
        int key, val, freq;
        Node *prev, *next;
        Node(int k, int v) : key(k), val(v), freq(1), prev(nullptr), next(nullptr) {}
    };

    struct DoublyLinkedList {
        Node *left, *right;
        int size;

        DoublyLinkedList() {
            left = new Node(0, 0);
            right = new Node(0, 0);
            left->next = right;
            right->prev = left;
            size = 0;
        }

        void pushRight(Node* node) {
            Node* p = right->prev;
            p->next = node;
            node->prev = p;
            node->next = right;
            right->prev = node;
            size++;
        }

        void pop(Node* node) {
            Node* p = node->prev;
            Node* n = node->next;
            p->next = n;
            n->prev = p;
            size--;
        }

        Node* popLeft() {
            Node* node = left->next;
            pop(node);
            return node;
        }
    };

    int capacity;
    int lfuCount;
    unordered_map<int, Node*> nodeMap;
    unordered_map<int, DoublyLinkedList*> listMap;

public:
    LFUCache(int capacity) : capacity(capacity), lfuCount(0) {}

    int get(int key) {
        if (nodeMap.find(key) == nodeMap.end()) return -1;
        Node* node = nodeMap[key];
        counter(node);
        return node->val;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (nodeMap.find(key) != nodeMap.end()) {
            Node* node = nodeMap[key];
            node->val = value;
            counter(node);
            return;
        }

        if ((int)nodeMap.size() == capacity) {
            Node* toRemove = listMap[lfuCount]->popLeft();
            nodeMap.erase(toRemove->key);
            delete toRemove;
        }

        Node* node = new Node(key, value);
        nodeMap[key] = node;
        if (listMap.find(1) == listMap.end()) {
            listMap[1] = new DoublyLinkedList();
        }
        listMap[1]->pushRight(node);
        lfuCount = 1;
    }

private:
    void counter(Node* node) {
        int count = node->freq;
        listMap[count]->pop(node);

        if (count == lfuCount && listMap[count]->size == 0) {
            lfuCount++;
        }

        node->freq++;
        if (listMap.find(node->freq) == listMap.end()) {
            listMap[node->freq] = new DoublyLinkedList();
        }
        listMap[node->freq]->pushRight(node);
    }
};
