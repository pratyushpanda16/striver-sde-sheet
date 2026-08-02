#include <string>
#include <vector>

using namespace std;

class Trie {
private:
    vector<Trie*> children;
    bool isEnd;

    Trie* traverse(string s) {
        Trie* node = this;
        for (char c : s) {
            int index = c - 'a';
            if (!node->children[index]) {
                return nullptr;
            }
            node = node->children[index];
        }
        return node;
    }

public:
    Trie() : children(26, nullptr), isEnd(false) {}

    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new Trie();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        Trie* node = traverse(word);
        return node != nullptr && node->isEnd;
    }

    bool startsWith(string prefix) {
        return traverse(prefix) != nullptr;
    }
};
