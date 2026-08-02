#include <string>
#include <vector>

using namespace std;

class Trie {
private:
    struct Node {
        Node* children[26] = {nullptr};
        int endCount = 0;
        int prefixCount = 0;
    };

    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) curr->children[idx] = new Node();
            curr = curr->children[idx];
            curr->prefixCount++;
        }
        curr->endCount++;
    }

    int countWordsEqualTo(string word) {
        Node* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) return 0;
            curr = curr->children[idx];
        }
        return curr->endCount;
    }

    int countWordsStartingWith(string prefix) {
        Node* curr = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!curr->children[idx]) return 0;
            curr = curr->children[idx];
        }
        return curr->prefixCount;
    }

    void erase(string word) {
        if (countWordsEqualTo(word) == 0) return;
        Node* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            curr = curr->children[idx];
            curr->prefixCount--;
        }
        curr->endCount--;
    }
};
